.data
source:
# Array source = {3, 1, 4, 1, 5, 9, 0}
    .word   3
    .word   1
    .word   4
    .word   1
    .word   5
    .word   9
    .word   0

dest:
# Array dest[10] = {0};
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0

.text
main:
	# Inicialização de k = 0;
    # t0 = k
    addi t0, x0, 0

    # Inicialização de sum = 0;
    # s0 = sum
    addi s0, x0, 0

    # Carregar os endereços dos arrays source e dest
    # funciona como ponteiros para os arrays
    la s1, source
    la s2, dest

# loop => for (k=0; source[k] != 0; k++)
loop:

	# aqui não é k++, é a representação de bytes de k++, onde ele vai somar com
    # o tamanho do int que representa somar 1, ele vai fazer um shift para esquerda
    # de 2, ou seja, multiplicar por 4, que é o tamanho da variável que estamos trabalhando
    # 
    # Então se temos k = 3, s3 receberá 12, que é a quantidade de bytes necessária para mover
    # k posições na memória, que trabalha com bytes
    #
    # Uma alusão a s3 = sizeof(int) * k
    slli s3, t0, 2

    # t1 recebe s1 + s3, ** significa que vai avançar em 1 posição no array source 
    # source[++k]
    # (endereço de source) + sizeof(int) * k => S sendo endereço de source => ** S + ( sizeof(int) * k ) ** 
    add t1, s1, s3

    # carrega a palavra de t1 para t2 => carrega o elemento S + (sizeof(int) * k) do array source
    # t2 = source[k]
    # em outras palavras, t2 = *(S + sizeof(int) * k)
    lw t2, 0(t1)

    # se t2 == 0 pule para exit, ** significa se encontrar o último elemento do array, parar o loop
    # for (k = 0; ** source[k] != 0 **; k++)
    beq t2, x0, exit

    # a0 recebe t2 + x0; a0 pode ser argumento de uma função ou o retorno da função
    # passando source[k] como parametro para fun(int x) como (int x)
    # PASSO 1: DEFINIR O REGISTRADOR PARA O ARGUMENTO DA FUNÇÃO
    add a0, x0, t2

    # Aloca espaço na memória (na pilha (stack)) para receber variáveis que queremos ter acesso em outro lugar
    # Como a pilha tem ordenação invertida, vamos decrementar n*4 bytes em sp (stack pointer), onde n é
    # ... o número de variáveis que queremos armazenar na pilha, e 4 é o tamanho do valor em bytes
    # ... e sp é o ponteiro indicando o topo da pilha, onde vamos ter controle dela
    #
    # Fizemos isso pois os registradores t0 e t2 vão ser usados na função fun(int x)
    # E queremos manter os valores que estavamo nela antes depois da função
    #
    # PASSO 3: ALOCA ESPAÇO PARA AS VARIÁVEIS LOCAIS
    addi sp, sp, -8
    
    # Guardas os valores nas variáveis que acabamos de alocar na memória
    sw t0, 0(sp)
    sw t2, 4(sp)

    # pula para square, provavelmente para resolver a função fun(int x)
    # PASSO 2: TRANSFERIR O CONTROLE PARA A FUNÇÃO
    # E salvando o localização dessa instrução no registrador ra permitindo o retorno a ela
    # ra é implícito por padrão
    jal square

    # Recupera os valores de t0 e t2 antes de chamar a função fun(int x)
    # carregando esses valores da pilha, que salvamos antes no PASSO 5
    lw t0, 0(sp)
    lw t2, 4(sp)

    # Estamos desalocando o espaço alocado na pilha anteriormente
    # Clean up
    # Como já carregamos os valores armazenados antes, podemos desalocar esse espaço
    # Faz parte do PASSO 5: CLEAN UP, LIMPAR A SUJEIRA
    addi sp, sp, 8

    # t2 está recebendo a0, o retorno que a função gerou
    add t2, x0, a0

    # D é o endereço de dest
    # t3 está recebendo o endereço de D somado com k
    # em outras palavras, t3 = &( D + k )
    # também, => ** dest[k]
    add t3, s2, s3

    # registrando o valor retornado da função fun(int x) em dest[k]
    # dest[k] = fun(int x)
    sw t2, 0(t3)

    # s0 está adicionando a ele mesmo t2, que é dest[k] e ao mesmo tempo o valor retornado de fun(int x)
    # sum = sum + dest[k]
    # sum += dest[k]
    add s0, s0, t2

    # k = k + 1
    # k++
    # incrementação de k para contagem do loop for
    addi t0, t0, 1

    # voltando para o loop
    jal x0, loop

# fun(int x)
square:
# PASSO 4: CORPO DA FUNÇÃO 

    # usando o reg temporário t0 para guardar o x, argumento da função
    add t0, a0, x0

    # usando o reg temporário t1 para guardar o x, argumento da função
    add t1, a0, x0

    # adicionando 1 ao t0, referente a (x + 1)
    addi t0, t0, 1

    # atribuindo o valor -1 ao registrador t2
    addi t2, x0, -1

    # multiplicando t1 por -1, praticamente trocando seu sinal, referente a (-x)
    mul t1, t1, t2

    # multiplicando (-x) * (x + 1), calculados anteriormente
    # retornando esse resultado para a função, no registrador a0
    # PASSO 5: DEVOLVER PARA UM REGISTRADOR O RETORNO DA FUNÇÃO
    mul a0, t0, t1

    # Voltar para a instrução anterior, retornando o controle para ela
    # Usamos o registrador ra que contém a localização da instrução anterior
    # ... para usar de referência e voltar para ela
    # PASSO 6: RETORNAR O CONTROLE PARA A FUNÇÃO ANTERIOR
    jr ra

# Finalizando a questão, imprimindo o resultado soma (sum)
exit:

    # registrando o resultado sum em a0, para chamada ecall de a0
    add a0, x0, s0

    # ????
    add a1, x0, x0

    # Fazendo a chamada especial do SO, usando o valor de a0, que é o resultado soma
    ecall # Terminate ecall
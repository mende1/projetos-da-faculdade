""" Solução
A solução se baseia em 3 etapas da criptografia, em que é usada funções do Python que facilita a manipulação de strings, e também analisar tambela ASCII.
A função ord() tranforma um caractere em seu valor númerico representado na tabela ASCII, e a função chr() recebe um valor númerico e retorna o caractere referente a esse valor númerico na tabela ASCII. Com isso, conseguimos fazer muito bem a manipulação e análise das strings.
Primeiro passo se baseia em pegar os caracteres que são letras [a-z, A-Z] e fazer a manipulação de 3 valores adiante na tabela ASCII.
O segundo passo foi apenas para inverter a string resultante do passo 1, usando recursos do python de range da string, foi trivial.
O terceiro passo, consistiu em manter a primeira metade da string resultante do passo 2, e manipular a segunda metade, de modo que os caracteres fossem mudados para 1 valor atrás, de acordo com a tabela ASCII.
"""

# Entrada da quatidade de casos de teste
n = int(input())

# Loop para os casos de teste
for i in range(n):

    # Entrada da string a ser analisada e criptografada
    str = input()

    # Aux1 = String auxiliar para pegar o resultado do primeiro passo da criptografia
    aux1 = ""

    # 1ª Passada:

    # Passear pela string e analisar os seus caracteres
    for char in str:

        # De acordo com as instruções, se o caractere for uma letra [a-z, A-Z], então faça a criptografia
        if char.isalpha():

            # Criptografia: 3 caracteres adiante aos caractere a ser criptografado, de acordo com a tabela ASCII
            # Tranforma o caractere original na representação númerica ASCII, adiciona 3, e tranforma novamente em char
            aux1 += chr(ord(char) + 3)

        # Caso não seja letra [a-z, A-Z], então não criptografe
        else:
            aux1 += char

    # 2ª Passada:

    # Aux2 = String para pegar o resultado do segundo passo da criptografia
    # Inverter a string apenas
    aux2 = aux1[::-1]

    # 3ª Passada:

    # Pega o valor da metade do tamanho da string
    half = len(aux2) // 2

    # Ans = String final com o resultado da criptografia inteira
    # Pega a primeira metade da string, apenas
    ans = aux2[:half]

    # Analisa a segunda metade da string, realizando a criptografia de 1 caractere a menos na tabela ASCII
    for char in aux2[half:]:
        ans += chr(ord(char) - 1)

    # Saída de dados, da string criptografada
    print(ans)

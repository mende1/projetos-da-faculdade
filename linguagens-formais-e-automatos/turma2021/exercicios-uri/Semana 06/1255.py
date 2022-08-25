""" Solução
A solução se baseia em, para cada caso de teste, analisar as strings e registrar a cardinalidade de ocorrências de cada caractere tem na string, registrando isso em um dicionário pela facilidade de identificação de variáveis. Usando funções python, como isalpha() para identificar letras (a-Z), count para conseguir a quantidade de vezes que um caractere aparece em uma string, a gente consegue então registrar as informações necessárias no dicionário, ordenar o dicionário com a referência de ordenação a ocorrência dos caracteres. E então, ter como saída dos dados os caracteres que mais apareceram na string.
"""

# Entrada da quantidade de casos de teste
n = int(input())

# Loop para os casos de teste
for i in range(n):

    # Entrada da string a ser analisada
    str = input()

    # Tranforma a string toda em minúscula, caso tenha caracteres maiúsculos
    str = str.lower()

    # Dicionário para guardar os caracteres que apareceram alguma vez na string
    chars = {}

    # Loop para passear pela string
    for c in str:

        # Caso o caractere seja uma letra (a-z) e que não tenha aparecido antes na string
        # Então, adicione o caractere no dicionário 'chars' fazendo uma relação com o caractere e a quantidade de vezes que ele apareceu, usando a função python 'count' que significa contar, retornando a quantidade de vezes que o caractere apareceu
        if c.isalpha() and c not in chars:
            chars[c] = str.count(c)

    # Ordena o dicionário, usando como referência de ordenação a cardinalidade de aparição do caractere na string
    chars_sort = sorted(chars.items(), key=lambda x: (-x[1],x[0]))

    # Pega a quantidade maior de aparecimentos de algum caractere
    bigger = chars_sort[0][1]

    # Loop para passear pelo dicionário ordenado
    # E imprime os caracteres que mais apareceram, de acordo com o número na variável 'bigger
    for c in chars_sort:
        if c[1] == bigger:
            print(c[0], end="")
        else:
            break
        
    # ENDL
    print()
    
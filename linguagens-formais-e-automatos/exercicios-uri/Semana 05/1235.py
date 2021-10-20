""" Solução
A solução se baseia em pegar as duas metades da string, invertelas separadamente, com a ajuda do recurdo do Python para análise de string/arrays, como o range que queremos pegar dessa string, e em qual sentido fazer a contagem. Por exemplo, [::-1], vai pegar a string inteira, porém invertida. E adicionar as duas metades invertidas à variável solução.
"""

# Entrada da quantidade de casos de teste
n = int(input())

# Loop para os casos de teste
for i in range(n):

    # Entrada da string a ser analisada
    str = input()

    # Ans = String final que será o resultado do caso de teste
    ans = ""

    # Contém o valor da metade do tamanho da string
    half = len(str) // 2

    # Half_1 = String que contém a primeira metade da string a ser analisada
    # Half_2 = String que contém a  segunda metade da string a ser analisada
    half_1 = str[:half]
    half_2 = str[half:]

    # Adiciona as metades invertidas à variável do resultado final
    # É usado o recurso do python de range das strings para facilitar a inversão. [::-1] pega a string invertida
    ans += half_1[::-1]
    ans += half_2[::-1]

    # Saída do resuldade do caso de teste
    print(ans.strip())

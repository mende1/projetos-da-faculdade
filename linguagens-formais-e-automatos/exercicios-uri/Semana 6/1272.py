""" Solução
A solução se baseia em usar a função python split() para separar todas as palavras da string separadas por algum separador, inclusive 1 espaço ou até vários. Após isso, apenas pegar a primeira letra de cada elemento do array com as palavras separadas, e pronto.
"""

# Entrada da quantidade dos casos de teste
t = int(input())

# Loop para os casos de teste
for i in range(t):

    # Entrada da string a ser analisada
    str = input()

    # Array que irá conter todas as palavras da string separadas por algum tipo de separados, seja ele 1 espaço ou até mesmo vários
    arr = [n for n in str.split()]

    # Variável Answer para armazenar a solução do caso de teste
    ans = ""

    # Loop para passear pelo array de palavras e adicionar à solução o primeiro caractere de cada elemento (string) do array
    for e in arr:
        ans += e[0]

    # Saída do caso de teste
    print(ans)

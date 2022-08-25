""" Solução
A solução é baseada em um array de referenciação, que relaciona um valor de 0 a 9, com uma quantidade necessária de leds para cada um desses valores.
É feita um loop para passear na string a ser analisada, tranformada cada caractere em inteiro, e usado como indície do array de referências.
É então pega os valores do array de acordo do o indície e adicionado a uma variável que será impressa no final dos casos de teste.
"""

# Array de referência para relacionar a quantidade de leds necessária para cada número de 0 a 9
# A referência é feita da seguinte forma:
# Os indícies do array de tamanho 10: 0 até 9, referencia os números a serem analisados
# Os valores de cada indície "leds[n]" se referem à quantidade de leds necessária para cada indície
leds = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

# Entrada dos casos de teste
n = int(input())

# Loop para os casos de teste
for i in range(n):

    # Entrada da string a ser analisada
    str = input()

    # Variável answer que definirá a quantidade final de leds da string
    ans = 0

    # Passear pela string e analisar char por char
    for char in str:

        # Tranforma o caractere em inteiro, e é usado como indície do array de referência da quatidade de Leds para cada número
        ans += leds[int(char)]

    # Saída dos dados para cada caso de teste
    print(ans, "leds")

""" Solução
A solução se baseia em pegar apenas as vogais existentes na string, usando um array de referência para tal, e verificar se essas vogais na ordem natural de leitura (esquerda => direita) são iguais na ordem inversa
"""

# Entrada da string
str = input()

# Array para referência contendo as vogais
vogais = ['a', 'e', 'i', 'o', 'u']

# Variável auxiliar que receberá apenas as vogais na ordem natural da leitura (=>)
aux = ""

# Loop para passear pela string, analisar cada caractere se pertece ao grupo das vogais, e adicionar à variável Auxiliar
for ch in str:
    if ch in vogais:
        aux += ch

# Utilizando do recurso de python [::-1] para pegar a string (array) na ordem inversa
# Verificando se as vogais que aparecem na string são iguais na ordem natural (==>) e na ordem inversa (<==)
if aux == aux[::-1]:
    print("S")
else:
    print("N")

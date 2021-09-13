""" Solução
A solução se baseia em achar a posição dos caracteres '+' e '=', e então a partir destas posições, achar os valores relacionados às incógnitas R, L e J. E após descobrir qual dos 3 é a incógnita da equação e tendo os outros 2 valores, resolvemos de forma simples e trivial o problema.
"""

# Loop para os casos de teste, até o EOF
while True:

    try:
        # Entrada da equação
        str = input()
        
        # Achar a posição dos caracteres '+' e '='
        pos_plus =  str.find('+')
        pos_equal = str.find('=')

        # Separa a equação em R, L e J, de acordo com a posição dos caracteres '+' e '='
        # Tudo atrás do '+' será a variável R, atrás do '=' será o L e após isso o J
        R = str[0:pos_plus]
        L = str[pos_plus+1:pos_equal]
        J = str[pos_equal+1:]

        # Verificações de qual parte da equação está indefinida, portante é a incógnita da equação
        # E para cada incógnita, é achado o valor dela de maneira diferente, em relação aos outros 2 valores
        if R == 'R':
            
            # R = J - L 
            print(int(J) - int(L))

        elif L == 'L':
            
            # L = J - R
            print(int(J) - int(R))

        elif J == 'J':
            
            # J = R + L
            print(int(R) + int(L))

    # Capta o EOF e finaliza os casos de teste
    except EOFError:
        break
n = int(input())

for i in range(n):
    str = input()

    aux = []
    for c in str:
        if c.isalpha():
            if c not in aux:
                aux.append(c)

    if len(aux) == 26:
        print("frase completa")
    elif len(aux) >= 13:
        print("frase quase completa")
    else:
        print("frase mal elaborada")

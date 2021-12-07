n = int(input())

gerais = [e for e in input().split()]

m = int(input())

proib = [e for e in input().split()]

q = int(input())

arr = [e for e in input().split()]

for i in range(q):
    key = arr[i]

    esq = 0
    dir = m-1

    achou = False

    while esq <= dir:
        meio = (esq + dir) // 2

        if proib[meio] == key:
            achou = True
            break
        elif key < proib[meio]:
            dir = meio - 1
        else:
            esq = meio + 1

    if achou:
        print('Proibido')
    else:
        print('Geral')

n = int(input())

lvr = []
ids = []

for i in range(n):
    livro, id = input().split()
    id = int(id)
    
    lvr.append(livro)
    ids.append(id)

x = int(input())

id = [e for e in input().split()]

for key in id:
    
    esq = 0
    dir = n-1

    achou = False

    while esq <= dir:

        meio = (esq + dir) // 2

        if key == lvr[meio]:
            achou = True
            break
        elif key < lvr[meio]:
            dir = meio - 1
        else:
            esq = meio + 1
        
    if achou:
        if ids[meio] == 1:
            print('Disponivel')
        elif ids[meio] == 2:
            print('Emprestado')
    else:
        print('Nao encontrado')


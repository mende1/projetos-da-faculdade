n = int(input())

arr = []

for i in range(n):
    arr.append(input())

x = int(input())

id = []

for i in range(x):
    id.append(input())

for key in id:
    
    esq = 0
    dir = n-1

    while esq <= dir:

        meio = (esq + dir) // 2

        if key == arr[meio]:
            break
        elif key < arr[meio]:
            dir = meio - 1
        else:
            esq = meio + 1
        
    if key != arr[meio]:
        print('Jaden nao pode se tornar o Rei dos Jogos')
        exit()


print('Jaden pode se tornar o Rei dos Jogos')

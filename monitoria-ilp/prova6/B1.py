n = int(input())

arr = [int(e) for e in input().split()]

x = int(input())

id = [int(e) for e in input().split()]

for key in id:
    
    esq = 0
    dir = n-1

    while esq <= dir:

        meio = (esq + dir) // 2

        if key == arr[meio]:
            print('Preparem o vidro de dragao!!!')
            exit()
        elif key < arr[meio]:
            dir = meio - 1
        else:
            esq = meio + 1


print('E assim termina nossa vigilia')

n = int(input())

arr = [int(e) for e in input().split()]

id = [int(e) for e in input().split()]

id.pop()

for key in id:
    
    esq = 0
    dir = n-1

    while esq <= dir:

        meio = (esq + dir) // 2

        if key == arr[meio]:
            print(meio)
            break
        elif key < arr[meio]:
            dir = meio - 1
        else:
            esq = meio + 1

    if key != arr[meio]:
        print('Nao foi visitado ainda.')

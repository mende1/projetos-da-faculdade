n = int(input())

arr = []

for i in range(n):
    str = input()
    arr.append(str)

q = int(input())

for i in range(q):
    str = input()

    esq = 0
    dir = n-1

    achou = False

    while esq <= dir:
        meio = (esq + dir) // 2

        if arr[meio] == str:
            achou = True
            break
        elif str < arr[meio]:
            dir = meio - 1
        else:
            esq = meio + 1

    if achou:
        print(str + ' vive!')
    else:
        print(str + ' foi extinto :(')


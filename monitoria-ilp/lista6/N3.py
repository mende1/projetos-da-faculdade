n = int(input())

arr = [e for e in input().split()]

x = int(input())

planetas = [e for e in input().split()]

mat = []

for i in range(n):
    j = [int(e) for e in input().split()]
    mat.append(j)


anterior, ans = 0, 0

for i in range(x):
    key = planetas[i]

    esq = 0
    dir = n-1

    achado = -1

    while esq <= dir:
        meio = (esq + dir) // 2

        if key == arr[meio]:
            achado = meio
            break
        elif key < arr[meio]:
            dir = meio - 1
        else:
            esq = meio + 1

    ans += mat[anterior][achado]
    anterior = achado

print(ans)

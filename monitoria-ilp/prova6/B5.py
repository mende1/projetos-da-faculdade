n, m = input().split()

n = int(n)
m = int(m)

arr = [int(e) for e in input().split()]

id = [int(e) for e in input().split()]

ans = 0

for key in id:
    
    esq = 0
    dir = n-1

    while esq <= dir:

        meio = (esq + dir) // 2

        if key == arr[meio]:
            ans += 1
            break
        elif key < arr[meio]:
            dir = meio - 1
        else:
            esq = meio + 1

print(ans)

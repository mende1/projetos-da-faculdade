n, m = [int(e) for e in input().split()] 

mat = []

for i in range(n):
    j = [int(e) for e in input().split()] 
    mat.extend(j)

mat.sort()

q = int(input())

arr = [int(e) for e in input().split()] 

for num in arr:

    esq = 0
    dir = len(mat)

    while esq < dir:

        meio = esq + (dir - esq) // 2

        if num < mat[meio]:
            dir = meio
        else:
            esq = meio + 1
        
    print(dir)

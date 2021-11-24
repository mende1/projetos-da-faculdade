n, m = [int(e) for e in input().split()]

mata = []
matb = []

for i in range(n):
    linha = [int(e) for e in input().split()]

    mata.append(linha)

for i in range(n):
    linha = [int(e) for e in input().split()]

    matb.append(linha)

for i in range(n):
    for j in range(m):
        print(mata[i][j] - matb[i][j], end=" ")
    print()


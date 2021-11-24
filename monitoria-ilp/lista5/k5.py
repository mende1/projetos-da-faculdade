n, m = [int(e) for e in input().split()]

mat = []
ans = 0

for i in range(n):
    linha = [int(e) for e in input().split()]

    mat.append(linha)

control = False

for i in range(n):
    vector = range(m) if not control else range(m-1, -1, -1)
    control = not control

    for j in vector:
        ovo = mat[i][j]
        ans += ovo
        if ans < 0:
            ans = 0

print(ans)

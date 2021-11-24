n, m = [int(e) for e in input().split()]

mat = []
ans = 0

for i in range(n):
    linha = [bool(int(e)) for e in input().split()]

    mat.append(linha)

for i in range(m):
    x, y = [int(e) for e in input().split()]

    for j in range(x, -1, -1):
        if mat[j][y]:
            mat[j][y] = False
            ans += 1
            break

print(ans)

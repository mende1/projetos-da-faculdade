mat = []

for i in range(7):
    j = [int(e) for e in input().split()]
    mat.append(j)

ans = 0
diag = 0

for i in range(7):
    ans += mat[i].count(1)
    diag += mat[i][i]

ans -= diag
ans //= 2
ans += diag
 
print(ans)
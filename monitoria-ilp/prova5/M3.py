n = int(input())

mat = []

for i in range(n):
    j = [int(e) for e in input().split()]
    mat.append(j)

ans = 0

t = int(input())

for T in range(t):
    x, y = [int(e) for e in input().split()]

    ans += mat[x][y]

print(ans)

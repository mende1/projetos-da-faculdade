n, m = [int(e) for e in input().split()]

mat = []

for i in range(n):
    j = [int(e) for e in input().split()]
    mat.append(j)

t = int(input())

for i in range(t):
    k, x, y = [int(e) for e in input().split()]

    ans = 0

    for j in range(x, y+1):
        ans += mat[k-1][j-1]

    print(ans)
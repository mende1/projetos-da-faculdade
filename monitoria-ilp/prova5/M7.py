n, m = [int(e) for e in input().split()] 

mat = []

for i in range(n):
    j = [int(e) for e in input().split()]

    mat.append(j)

for i in range(n):
    for j in range(m):
        if mat[i][j] == 0:
            if i == 0:
                if mat[i][j+1] == 1 and mat[i][j-1] == 1 and mat[i+1][j] == 1:
                    print(i, j)
                    exit()
            if j == 0:
                if mat[i+1][j] == 1 and mat[i-1][j] == 1 and mat[i][j+1] == 1:
                    print(i, j)
                    exit()
            if i == n-1:
                if mat[i][j+1] == 1 and mat[i][j-1] == 1 and mat[i-1][j] == 1:
                    print(i, j)
                    exit()
            if j == m-1:
                if mat[i+1][j] == 1 and mat[i-1][j] == 1 and mat[i][j-1] == 1:
                    print(i, j)
                    exit()
            if mat[i+1][j] == 1 and mat[i-1][j] == 1 and mat[i][j+1] == 1 and mat[i][j-1] == 1:
                print(i, j)
                exit()

print(0, 0)

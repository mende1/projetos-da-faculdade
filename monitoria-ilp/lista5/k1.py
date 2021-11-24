n = int(input())

mat = []

for i in range(10):
    row = [int(e) for e in input().split()]

    mat.append(row)

for i in range(10):
    for j in range(10):
        if mat[i][j] >= n:
            print("sim")
            exit()

print("nao")

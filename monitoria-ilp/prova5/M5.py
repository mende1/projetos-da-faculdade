n, m = [int(e) for e in input().split()]

mat = []

for i in range(n):
    j = [int(e) for e in input().split()]
    mat.append(j)

for i in range(n):
    for j in range(m-1):
        if mat[i][j] == 0 and mat[i][j+1] == 0:
            print('Fileira:', i+1)
            print('Assentos: ' + str(j+1) + ' e ' + str(j+2))
            break 

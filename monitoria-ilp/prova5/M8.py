n, m = [int(e) for e in input().split()]

mat = []

for i in range(n):
    j = [int(e) for e in input().split()]

    mat.append(j)

x, y = [int(e) for e in input().split()]

# Lado A e C

lado_a = 0
lado_c = 0
for j in range(m):
    lado_a += mat[0][j]
    lado_c += mat[n-1][j]

# Lado B e D

lado_b = 0
lado_d = 0
for i in range(n):
    lado_b += mat[i][m-1]
    lado_d += mat[i][0]

lado_a /= m
lado_c /= m

lado_b /= n
lado_d /= n

topo = mat[x][y]

lados = [lado_a, lado_b, lado_c, lado_d]
desniveis = [topo - lado for lado in lados]

ans = -1
maxi = -1

for i in range(4):
    if desniveis[i] > maxi:
        maxi = desniveis[i]
        ans = i

if ans == 0:
    print('Lado A')
elif ans == 1:
    print('Lado B')
elif ans == 2:
    print('Lado C')
elif ans == 3:
    print('Lado D')

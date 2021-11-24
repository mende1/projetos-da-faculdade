n, m = [int(e) for e in input().split()]

mat = []

for i in range(n):
    j = [bool(int(e)) for e in input().split()]
    mat.append(j)

t = int(input())

for i in range(t):
    l, c = [int(e)-1 for e in input().split()]

    mat[l][c] = False

for i in range(n):
    if mat[i].count(True) > 0:
        print('ILL BE BACK')
        exit()

print('HASTA LA VISTA BABY')

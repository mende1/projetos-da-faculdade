n, m = [int(e) for e in input().split()]

mat = []
aux = [0] * 101

for i in range(n):
    linha = [int(e) for e in input().split()]

    for j in linha:
        aux[j] += 1
    
p = int(input())

ans = aux[p]

print('Ash pegou ' + str(ans) + ' pokemon')

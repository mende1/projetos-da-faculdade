n = int(input())

homens = [int(e) for e in input().split()]
mulheres = [int(e) for e in input().split()]

for inicio in range(1, n):
    i = inicio
    while i >= 1 and homens[i] > homens[i-1]:
        homens[i], homens[i-1] = homens[i-1], homens[i]
        i -= 1

for inicio in range(1, n):
    i = inicio
    while i >= 1 and mulheres[i] < mulheres[i-1]:
        mulheres[i], mulheres[i-1] = mulheres[i-1], mulheres[i]
        i -= 1

for i in range(n):
    print(homens[i], mulheres[i])
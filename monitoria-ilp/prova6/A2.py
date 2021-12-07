n, m = input().split()

n = int(n)
m = int(m)

arv = []
alt = []

for i in range(n):
    arvore, altura = input().split()
    altura = int(altura)

    arv.append(arvore)
    alt.append(altura)

for fim in range(n-1, 0, -1):
    imenor = 0

    for i in range(0, fim + 1):
        if alt[i] < alt[imenor]:
            imenor = i

    alt[imenor], alt[fim] = alt[fim], alt[imenor]
    arv[imenor], arv[fim] = arv[fim], arv[imenor]

for i in range(m):
    print(arv[i])

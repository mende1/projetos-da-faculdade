n = int(input())

xama = 0

for i in range(n):
    p = int(input())
    xama += p * 0.05

print(xama)
print(p)

if xama > p:
    print("Escolheu o seu destino!")
else:
    print("Fez de mim o que eu sou!")

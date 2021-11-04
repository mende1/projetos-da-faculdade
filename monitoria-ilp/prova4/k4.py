x, y = [int(e) for e in input().split()]

valor = [int(e) for e in input().split()]
danos = [int(e) for e in input().split()]

comprou = False

maior = 0
if valor[0] <= x:
    comprou = True

for i in range(1, len(danos)):
    if danos[i] > danos[maior] and valor[i] <= x:
        maior = i
        comprou = True

if comprou:
    print(valor[maior], danos[maior])
else:
    print("Yan Pobre")


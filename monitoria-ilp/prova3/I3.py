n = int(input())

media = 0

for i in range(n):
    p = float(input())

    media += p

media /= n

if media > 4:
    print("VAI MITAR")
else:
    print("Jogador inconsistente")

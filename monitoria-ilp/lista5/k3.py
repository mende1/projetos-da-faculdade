n = int(input())

plant = []

harry, ron = 0, 0

for i in range(n):
    linha = [int(e) for e in input().split()]

    plant.append(linha)

x, y = [int(e) for e in input().split()]

for i in range(n):
    harry += plant[x][i]
    ron   += plant[i][y]

if x == y:
    harry -= plant[x][y]
elif y > x:
    harry -= plant[x][y]
else:
    ron   -= plant[x][y]

print("Harry", harry)
print("Ron", ron)

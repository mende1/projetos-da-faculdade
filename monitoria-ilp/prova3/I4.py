n = int(input())

matou = 0
morreu = 0

for i in range(n):
    a, b = [int(e) for e in input().split()]
    matou += a
    morreu += b

if matou > morreu:
    print("Sou barril dobrado")
else:
    print("Sou nube")

n = int(input())

arr = [int(e) for e in input().split()]
bar = [int(e) for e in input().split()]

count = 0

for carta in bar:
    for i in arr:
        if carta == i:
            count += 1
            break

print("Exodia Obliterar" if count == len(bar) else "Voce perdeu Yugi")

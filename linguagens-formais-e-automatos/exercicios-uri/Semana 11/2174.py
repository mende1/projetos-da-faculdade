n = int(input())

pomekons = []

for i in range(n):
    str = input()

    if str not in pomekons:
        pomekons.append(str)

print(f"Falta(m) {151 - len(pomekons)} pomekon(s).")
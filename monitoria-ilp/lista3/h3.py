n, x, xpmin = [int(e) for e in input().split()]

for i in range(n):
    xp, q = [int(e) for e in input().split()]
    if xp >= xpmin:
        print(xp + x, q + 1)
    else:
        print(xp, q)

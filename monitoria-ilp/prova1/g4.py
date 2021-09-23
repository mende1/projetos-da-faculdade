x, y, r = [int(n) for n in input().split()]

area = x * y
leite = 2 * r

ax = x // leite
ay = y // leite

ans = ax * ay
print(ans)

x, y, z = [int(n) for n in input().split()]
a, b, c = [int(n) for n in input().split()]

ax = x // a
by = y // b
cz = z // c

ans = ax * by * cz
print(ans)

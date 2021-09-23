t, d = [int(n) for n in input().split()]
v, p = [int(n) for n in input().split()]

ans = (t * v) + ((t // d) * p)
print(ans)

n = int(input())

u = [int(e) for e in input().split()]
v = [int(e) for e in input().split()]
D = [int(e) for e in input().split()]

ok = True

for i in range(n):
    if u[i] + v[i] != D[i]:
        ok = False
        break

if ok:
    print("OK")
else:
    print("NOPE :(")

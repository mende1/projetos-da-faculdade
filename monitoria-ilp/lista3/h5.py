e, p = [int(t) for t in input().split()]

ans = 0

while e > 0 and p > 0:

    e -= p
    p -= 1
    ans += 1

if e > 0:
    print('F')
else:
    print(ans)

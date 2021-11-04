n = int(input())

arr = [int(e) for e in input().split()]
c = int(input())

ans = 0

for e in arr:
    if e == c:
        ans -= e
    else:
        ans += e

print(ans)

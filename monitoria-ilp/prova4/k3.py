n = int(input())

arr = [int(e) for e in input().split()]
q = int(input())

ans = 0

for i in arr:
    if ans + i <= q:
        ans += i
    else:
        break

print(ans // 100)

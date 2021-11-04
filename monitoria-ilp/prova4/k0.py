n = int(input())

arr = [int(e) for e in input().split()]

ans = 0

for i in arr:
    if i % 2 == 0:
        ans += i / 4
    else:
        ans += i * 3

print("{:.1f}".format(ans))

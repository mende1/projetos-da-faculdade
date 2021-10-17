n, m = [int(t) for t in input().split()]

ans = 0

for i in range(n):
    arr = input().split()
    sum = 0
    for j in arr:
        sum += int(j)

    if sum > ans:
        ans = sum

print(ans)

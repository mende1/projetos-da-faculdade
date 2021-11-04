n = int(input())

ans = 0

for i in range(n):
    a, b, c, d = [int(e) for e in input().split()]
    sum = 0

    if a + b + c + d < 100:
        sum += a + b + c + d
    else:
        sum += a - b - c - d

    ans += sum

print(ans, "anos de vida")

n = int(input())

ans = 0

for i in range(n):
    l, m, t = [int(e) for e in input().split()]
    
    ans += (l * m) + t

print(ans)

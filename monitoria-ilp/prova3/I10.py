n = int(input())

best = 101
kill = 0
dano = 0

for i in range(n):
    p, a, d = [int(e) for e in input().split()]
    
    if p < best:
        best = p
    
    kill += a
    dano += d

print(best, kill, dano)

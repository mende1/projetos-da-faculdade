n = int(input())

arr = [int(e) for e in input().split()]

c = int(input())

for i in arr:
    if i == c:
        print(i)
        exit()

print(-1)

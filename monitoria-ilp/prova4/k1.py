n = int(input())

arr = [int(e) for e in input().split()]
y = int(input())

for i in arr:
    print(i * y, end=" ")

print()
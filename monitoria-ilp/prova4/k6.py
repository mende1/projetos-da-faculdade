n = int(input())

arr = [int(e) for e in input().split()]
yoda = int(input())

yoda /= 2

for i in range(n):
    if arr[i] >= yoda:
        print(i, end=" ")

print()

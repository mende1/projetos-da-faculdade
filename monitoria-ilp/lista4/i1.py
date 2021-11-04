n = int(input())

arr = [int(e) for e in input().split()]

for i in arr[::-1]:
    print(i, end=" ")

print()
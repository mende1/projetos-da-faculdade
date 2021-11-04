s, n = map(int, input().split())

arr = [0] * n

for i in range(s):
    p = int(input())

    for j in range(0, len(arr), p):
        arr[j] = 1

for i in arr:
    print(i, end=" ")

print()

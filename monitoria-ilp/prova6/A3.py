n = int(input())

arr = []
ans = 0

for i in range(n):
    str = input()
    arr.append(str)

    if len(str) > 5:
        ans += 1

for fim in range(n-1, 0, -1):
    imenor = 0

    for i in range(0, fim + 1):
        if arr[i] > arr[imenor]:
            imenor = i

    arr[imenor], arr[fim] = arr[fim], arr[imenor]

for i in range(n):
    print(arr[i])

print(ans)

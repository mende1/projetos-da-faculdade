n = int(input())

arr = []

for i in range(n):
    arr.append(input())

for fim in range(n-1, 0, -1):
    imenor = 0

    for i in range(0, fim + 1):
        if len(arr[i]) > len(arr[imenor]):
            imenor = i

    arr[imenor], arr[fim] = arr[fim], arr[imenor]

for i in range(n):
    print(arr[i])

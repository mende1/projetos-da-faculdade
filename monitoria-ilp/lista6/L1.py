n = int(input())

arr = [int(e) for e in input().split()]

for inicio in range(1, n):
    i = inicio

    while i >= 1 and arr[i] < arr[i-1]:
        arr[i], arr[i-1] = arr[i-1], arr[i]

        i -= 1

for i in range(8):
    print(arr[i], end=" ")
print()

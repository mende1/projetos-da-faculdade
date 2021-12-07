n = int(input())

ids = []
arr = []

for i in range(n):
    id, num = input().split()
    ids.append(int(id))
    arr.append(int(num))

for inicio in range(1, n):
    i = inicio
    while i >= 1 and arr[i] > arr[i-1]:
        arr[i], arr[i-1] = arr[i-1], arr[i]
        ids[i], ids[i-1] = ids[i-1], ids[i]
        i -= 1


for i in range(n):
    print(ids[i], arr[i])
n = int(input())

arr = []

for i in range(n):
    arr.append(int(input()))

for fim in range(n-1, 0, -1):
    imaior = 0

    for i in range(0, fim + 1):
        if arr[i] > arr[imaior]:
            imaior = i

    arr[imaior], arr[fim] = arr[fim], arr[imaior]


for i in range(n):
    print(arr[i])

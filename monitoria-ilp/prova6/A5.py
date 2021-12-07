n = int(input())

arr = [int(e) for e in input().split()]

for fim in range(n-1, 0, -1):

    imenor = 0

    for i in range(0, fim + 1):
        if arr[i] > arr[imenor]:
            imenor = i

    arr[fim], arr[imenor] = arr[imenor], arr[fim]

print(arr[(n//2)])

n = int(input())

arr = [int(e) for e in input().split()]

sum = 0
for i in arr:
    sum += i

aux = 0
for i in range(len(arr)):
    aux += arr[i]
    if aux == sum//2:
        print(i+1)
        break

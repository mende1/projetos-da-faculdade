m = int(input())
n = int(input())

arr =   [int(e) for e in input().split()]
bonus = [int(e) for e in input().split()]

sum = 0
for i in range(n):
    sum += arr[i] * bonus[i]

if sum >= m:
    print("Upou de Nivel!")
else:
    print("Nao foi dessa vez!")

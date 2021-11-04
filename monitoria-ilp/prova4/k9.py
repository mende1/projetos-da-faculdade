n = int(input())

arr = [int(e) for e in input().split()]
p = int(input())

sum = 0
for i in range(p):
    sum += arr[i]

if sum % 2 == 0:
    print("tutturu")
else:
    print("SERN")

n = int(input())

arr = [int(e) for e in input().split()]

ans = [0] * 1000000

for i in arr:
    ans[i] += 1

for i in range(len(ans)):
    if ans[i]:
        print(i, end=" ")

print()

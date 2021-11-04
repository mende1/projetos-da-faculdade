str = input()

n, substr = input().split()
n = int(n)

arr = str.split()
str = "".join(arr)

ans = str.count(substr)

print(ans)

if ans == n:
    print("SIM!")
else:
    print("NAO!")

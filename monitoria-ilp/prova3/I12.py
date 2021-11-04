n = int(input())

for j in range(1, n+1):
    for i in range(n-j):
        print(" ", end="")
    for i in range(j * 2 - 1):
        print(j, end="")
    print()


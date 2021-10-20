n = int(input())

for i in range(n):
    com, fim = map(int, input().split())

    for j in range(com, fim+1):
        print(j, end="")
    for j in range(fim, com-1, -1):
        aux = str(j)
        print(aux[::-1], end="")

    print()
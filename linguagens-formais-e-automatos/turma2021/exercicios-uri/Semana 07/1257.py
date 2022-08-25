n = int(input())

for i in range(n):
    L = int(input())

    ans = 0
    for j in range(L):
        
        str = input()

        value = 0

        for c in range(len(str)):
            value += ord(str[c]) - 65
            value += j
            value += c

        ans += value

    print(ans)

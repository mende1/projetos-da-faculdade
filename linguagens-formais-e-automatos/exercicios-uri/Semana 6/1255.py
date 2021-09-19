import sys

n = int(input())

for i in range(n):

    str = input()
    str = str.lower().replace(" ", "")

    arr = [0] * len(str)

    aux = str
    str = ""

    for c in aux:
        if c.isalpha():
            str += c

    for c in range(len(str)):
        for a in range(c, len(str)):
            if str[a] == str[c]:
                arr[c] += 1

    max = -sys.maxsize

    for c in range(len(str)):
        if arr[c] > max:
            max = arr[c]

    for c in range(len(str)):
        if arr[c] == max:
            print(str[c], end="")

    print()

m, n = [int(e) for e in input().split()]

while m != 0 or n != 0:

    string = str(m + n)

    ans = string.replace('0', '')

    print(ans)

    m, n = [int(e) for e in input().split()]

n = int(input())

for i in range(n):
    str = input()
    arr = str.split()

    for e in range(len(arr)-1):
        print(arr[e][0].upper(), end=". ")

    print(arr[len(arr)-1].capitalize())

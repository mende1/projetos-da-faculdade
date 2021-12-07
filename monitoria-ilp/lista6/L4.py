n, c, o = input().split()

n = int(n)

arr1 = []
arr2 = []

for i in range(n):
    nome, lvl = input().split()

    if c == 'N':
        arr1.append(nome)
        arr2.append(int(lvl))

    elif c == 'L':
        arr1.append(int(lvl))
        arr2.append(nome)

for inicio in range(1, n):
    i = inicio

    while i >= 1 and (arr1[i] < arr1[i-1] if o == 'C' else arr1[i] > arr1[i-1]):
        arr1[i], arr1[i-1] = arr1[i-1], arr1[i]
        arr2[i], arr2[i-1] = arr2[i-1], arr2[i]
        i -= 1

for i in range(n):
    print(arr1[i], arr2[i]) if c == 'N' else print(arr2[i], arr1[i])
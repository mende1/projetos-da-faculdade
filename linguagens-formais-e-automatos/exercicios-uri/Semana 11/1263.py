while True:
    try:
        str = input().lower()
        arr = str.split()
        ans = 0

        last = ''

        for i in range(len(arr)-1):

            if arr[i][0] == arr[i+1][0] and last != arr[i][0]:
                last = arr[i][0]
                ans += 1
            else:
                last = arr[i][0]

        print(ans)

    except EOFError:
        break
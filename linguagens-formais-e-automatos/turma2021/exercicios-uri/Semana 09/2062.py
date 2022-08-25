n = int(input())

ans = []

arr = input().split()

for e in arr:
    if len(e) == 3:
        if e.find("UR") == 0:
            ans.append("URI")
            continue
        elif e.find("OB") == 0:
            ans.append("OBI")
            continue

    ans.append(e)

for e in range(len(ans)-1):
    print(ans[e], end=" ")

print(ans[len(ans)-1])

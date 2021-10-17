t = int(input())

p = int(input())
alarme = 0
while p != 0:
    if p > t:
        alarme = 1

    p = int(input())

if alarme:
    print("ALARME")
else:
    print("O Havai pode dormir tranquilo")

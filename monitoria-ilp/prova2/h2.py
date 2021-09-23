ec, an, es = [int(n) for n in input().split()]

if ec < 6:
    print(6 - ec, 60 - an, 3 - es)
else:
    print("Final Verdadeiro")

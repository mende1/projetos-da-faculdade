n = int(input())

arr = [int(e) for e in input().split()]

vida = int(input())
vida_antiga = vida

for i in arr:
    if i == 1:
        vida = vida_antiga
    else:
        vida -= i
        if vida <= 0:
            print("You Died")
            exit()
    
print("Yes, you can")

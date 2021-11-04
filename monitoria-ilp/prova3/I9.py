n, a, b = [int(e) for e in input().split()]

n_impar = 0

for i in range(a, b+1):
    if i % 2 == 1:
        n_impar += 1

if n_impar < n:
    print("Falhamos galera")

else:
    aux = 0
    for i in range(a, b+1):
        if i % 2 == 1:
            if aux < n:
                print(i, end="")
                aux += 1
            else:
                break
    
    print()

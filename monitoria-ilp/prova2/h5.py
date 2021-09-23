n = int(input())

lm = n // 3

vv = (n - lm) // 2

cv = (n - lm - vv)

print("Vermelho", cv)
print("Azul", vv)
print("Amarelo", lm)

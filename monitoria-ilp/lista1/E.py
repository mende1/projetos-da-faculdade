c = int(input())

centena = c // 100
dezena = (c - centena*100) // 10
unidade = (c - centena*100 - dezena*10)

print(unidade, dezena, centena)
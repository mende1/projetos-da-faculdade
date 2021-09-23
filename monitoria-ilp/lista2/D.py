z, g = input().split()
d, c = input().split()

if z == d:
	print("Driblado")
	if g == c:
		print("Gol")
	else:
		print("...e o goleiro pega")

else:
	print("Bloqueado")
	
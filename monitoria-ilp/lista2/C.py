x = int(input())
y = int(input())

if x == 0 and y == 0:
	print("Centro")

elif x > 0 and y > 0:
	print("Quadrante 1")

elif x < 0 and y > 0:
	print("Quadrante 2")

elif x < 0 and y < 0:
	print("Quadrante 3")

else:
	print("Quadrante 4")

	
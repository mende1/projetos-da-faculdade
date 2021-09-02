a, b = input().split()

while a != "0" or b != "0":
	b = b.replace(a, "")
	if b == "":
		b = 0
	b = int(b)
	print(b)

	a, b = input().split()


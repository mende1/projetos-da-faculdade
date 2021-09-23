n1, n2, n3, n4, n5, n6 = [int(n) for n in input().split()]

ans = n1 + n2 + n3 + n4 + n5 + n6

if ans >= 250:
	print("S+")
elif ans >= 200:
	print("S")
elif ans >= 180:
	print("S-")
elif ans >= 150:
	print("A+")
elif ans >= 100:
	print("A")
elif ans >= 80:
	print("A-")
elif ans >= 60:
	print("B+")
elif ans >= 40:
	print("B")
else:
	print("B-")

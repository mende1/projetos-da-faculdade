n = int(input())

while n:
	n -= 1

	n1, n2 = input().split()

	len1 = len(n1)
	len2 = len(n2)

	if len2 > len1:
		print("nao encaixa")
		continue

	aux = ''

	for i in range(len1-len2, len1):
		aux += n1[i]

	if aux == n2:
		print("encaixa")
	else:
		print("nao encaixa")

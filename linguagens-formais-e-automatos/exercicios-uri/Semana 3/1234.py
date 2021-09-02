while True:

	try:
		str = input()

		ans = ''
		control = True

		for n in str:
			if n != ' ':
				if control:
					ans += n.upper()
				else:
					ans += n.lower()

				control = not control
			
			else:
				ans += n	

		print(ans)

	except EOFError:
		break

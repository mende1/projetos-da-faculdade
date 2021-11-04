str = input()

str = str.replace(" ", "").lower()

if str == str[::-1]:
    print("Palindromo")
else:
    print("!Palindromo")

while True:

    try:
        str = input()

        if len(str) < 6 or len(str) > 32:
            print("Senha invalida.")
            continue

        lower, upper, num = [0, 0, 0]

        is_special = False

        for ch in str:
            if ch.isalpha():
                if ord(ch) not in range(65, 91) and ord(ch) not in range(97, 123):
                    is_special = True
                    break
                if ch.islower():
                    lower += 1
                elif ch.isupper():
                    upper += 1
            elif ch.isdigit():
                num += 1
            else:
                is_special = True
                break

        if is_special:
            print("Senha invalida.")
            continue
            
        if not lower or not upper or not num:
            print("Senha invalida.")
            continue

        print("Senha valida.")
                

    except EOFError:
	    break
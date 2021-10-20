while True:

    try:
        str = input()
        ans = ""

        control_it = False
        control_bold = False

        symbols = "_*"

        for i in str:
            if i not in symbols:
                ans += i
            else:
                if i == "_":
                    if control_it:
                        ans += "</i>"
                        control_it = False
                    else:
                        ans += "<i>"
                        control_it = True
                elif i == "*":
                    if control_bold:
                        ans += "</b>"
                        control_bold = False
                    else:
                        ans += "<b>"
                        control_bold = True

        print(ans)

    except EOFError:
        break
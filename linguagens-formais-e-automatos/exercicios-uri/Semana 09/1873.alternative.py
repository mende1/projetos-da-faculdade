n = int(input())

for i in range(n):
    raj, sheldon = input().split()
    
    if raj == sheldon:
        print("empate")
    else:
        if raj == "tesoura":
            if sheldon == "papel" or sheldon == "lagarto":
                print("rajesh")
            else:
                print("sheldon")
        elif raj == "papel":
            if sheldon == "pedra" or sheldon == "spock":
                print("rajesh")
            else:
                print("sheldon")
        elif raj == "pedra":
            if sheldon == "lagarto" or sheldon == "tesoura":
                print("rajesh")
            else:
                print("sheldon")
        elif raj == "lagarto":
            if sheldon == "spock" or sheldon == "papel":
                print("rajesh")
            else:
                print("sheldon")
        elif raj == "spock":
            if sheldon == "pedra" or sheldon == "tesoura":
                print("rajesh")
            else:
                print("sheldon")
                
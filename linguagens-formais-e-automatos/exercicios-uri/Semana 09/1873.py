n = int(input())

rules = {
    "tesoura": ["papel", "lagarto"], 
    "papel": ["pedra", "spock"], 
    "pedra": ["lagarto", "tesoura"],
    "lagarto": ["spock", "papel"],
    "spock": ["pedra", "tesoura"]
}

for i in range(n):
    raj, sheldon = input().split()
    
    if raj == sheldon:
        print("empate")
    else:
        if sheldon in rules[raj]:
            print("rajesh")
        else:
            print("sheldon")

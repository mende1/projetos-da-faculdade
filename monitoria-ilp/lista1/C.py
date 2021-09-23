kanto, johto, hoenn = input().split()
catch_kanto, catch_johto, catch_hoenn = input().split()

total_kanto = int(kanto) + int(catch_kanto)
total_johto = int(johto) + int(catch_johto)
total_hoenn = int(hoenn) + int(catch_hoenn)

print(f"{total_kanto} {total_johto} {total_hoenn}")
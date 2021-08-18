segundos = int(input())

horas = int(segundos / 3600)
minutos = int(int(segundos % 3600) / 60)
segundos  = segundos % 60 

print(f'{horas}h {minutos}m {segundos}s')
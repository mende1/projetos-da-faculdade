cx, ovo, leite, xi = [int(n) for n in input().split()]

int_cx = cx // 4
int_ovo = ovo // 8
int_leite = leite // 2
int_xi = xi // 1

min = int_cx

if int_ovo < min:
	min = int_ovo

if int_leite < min:
	min = int_leite

if int_xi < min:
	min = int_xi

seg = min * 1259

hora = seg // 3600

seg -= hora * 3600

minuto = seg // 60

seg -= minuto * 60

print(hora, " h ", minuto, " m ", seg, " s" , sep="")
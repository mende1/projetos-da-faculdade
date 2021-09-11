#
# Aluno: Gustavo Mendel Queiroz e Souza
# E-mail: gustavo.mendel.br@gmail.com
#

# Usado como base o seguinte código em C:

# int factorial (int N) {
#     int Result = 1;
    
#     for (int i=N; i != 1; i--) {
#     	Result = Result * i;
#     }
#     return Result;
# }

# int main () {
# 	int N = 8;
#     printf("%d\n", factorial(N));
# }

.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall 					# Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall 					# Print newline

    addi a0, x0, 10
    ecall 					# Exit

factorial:
    add t0, x0, a0      	# int N
    addi s0, x0, 1      	# Result = 1
    add t1, x0, t0     		# int i=N controlador do loop
    addi t2, x0, 1      	# condição de parada (i != 1)

    addi sp, sp, -4
    sw ra, 0(sp)			
    
    jal ra, loop        	# Loop => for (int i=N; i != 1; i--)

    lw ra, 0(sp)
    addi sp, sp, 4

    add a0, x0, s0			# return Result

    jr ra					# Volta para a Main

loop:
    mul s0, s0, t1			# Result = Result * i
    addi t1, t1, -1			# Incrementa i = i - 1;
    bne t1, t2, loop		# if (i != 1)
    jr ra					# Volta para Factorial

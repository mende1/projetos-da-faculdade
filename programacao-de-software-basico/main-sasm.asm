%include "io.inc"
MSG_SIZE equ 61
STDIN equ 0
STDOUT equ 1
SYS_READ equ 3
SYS_WRITE equ 4
INITIAL_JMP equ 7
PARTIAL_MSG_SIZE equ 41
PARTIAL_MSG_CONCAT_SIZE equ 36
TO_UPPER equ 32
MIN_A_POS_ASCII equ 96

section .data

section .bss
  str: resb MSG_SIZE
  strPartial: resb PARTIAL_MSG_SIZE
  strReverse: resb PARTIAL_MSG_SIZE
  strConcat: resb PARTIAL_MSG_CONCAT_SIZE
  strUpper: resb PARTIAL_MSG_SIZE
  letterNum: resb PARTIAL_MSG_CONCAT_SIZE


section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    ; Limpando...
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    xor esi, esi
    xor edi, edi
    mov ebp, esp; for correct debugging
    GET_STRING str, 62
    ; LETRA A ============================================

    PRINT_STRING 'Letra A ----- '

    ; Copiar parte de str para strCopy
    mov ecx, PARTIAL_MSG_SIZE
    mov esi, str+INITIAL_JMP
    mov edi, strPartial
    rep movsb ; Repete a operação de mover o caracter até completar os 42 da substring
    
    PRINT_STRING strPartial
    NEWLINE

    ; LETRA B ============================================

    NEWLINE
    PRINT_STRING 'Letra B ----- '
    mov ecx, PARTIAL_MSG_SIZE
    mov ebx, 0 ; count
    mov esi, strPartial
    lodsb

  conta:
    cmp eax, 'a' ; Compara com A
    je l1 ; Vai pra l1 se é A
    cmp eax, 'm' ; Compara com M
    je l1 ; Vai pra l1 se é A
    lodsb ; Carrega o proximo char
    loop conta ; Faz o loop em ecx
    jmp end_l1 ; evita passar por l1 +1 vez no final do loop
    
  l1:
    lodsb ; Carrega o proximo char
    inc ebx ; somador
    sub ecx, 1
    cmp ecx, 0 ; evita loop inifinto
    jne conta

  end_l1:
    PRINT_DEC 1,ebx
    NEWLINE

    ; Letra C ============================================
    
    NEWLINE
    PRINT_STRING 'Letra C ----- '
    mov ecx, PARTIAL_MSG_SIZE
    mov esi, strPartial
    mov edi, strReverse
    add esi, ecx    ; Ponteiro source apontando para o final da string
    sub esi, 1      ; Ajusta esi para base 0
    
  reverse:
    std             ; Seta a direction flag para decrementar
    lodsb           ; Le a partir do fim da string
    cld             ; Seta a direction flag para incrementar
    stosb           ; Armazena a partir do inicio da string
    loop reverse
    
    PRINT_STRING strReverse
    NEWLINE

    ; Letra D ============================================
    
    NEWLINE
    PRINT_STRING 'Letra D ----- '
    mov ecx, PARTIAL_MSG_SIZE
    mov esi, strPartial
    mov edi, strConcat
    
  concat:
    lodsb ; Carrega o proximo char
    cmp eax, ' ' ; compara com espaço
    je space ; pula o stosb
    stosb ; Coloca o char no strConcat
  space:
    loop concat
    
    PRINT_STRING strConcat
    NEWLINE

    ; Letra E ============================================

    NEWLINE
    PRINT_STRING 'Letra E ----- '

    mov ecx, PARTIAL_MSG_SIZE
    mov esi, strPartial
    mov edi, strUpper
    mov ebx, 0

  upper:
    lodsb
    cmp eax, ' '
    je upperIgnore
    cmp ebx, 2 ; Caso menor que dois - Coloca em maiusculo
    jl l2
    cmp ebx, 4 ; Caso maior que dois e menor que quatro - deixa igual
    jl l3
    cmp ebx, 4 ; Reseta contador
    je l4
  upperIgnore:
    stosb
    loop upper
    jmp end_l4

  l2:
    sub ecx, 1
    inc ebx
    sub eax, TO_UPPER
    stosb
    cmp ecx, 0
    jne upper
    jmp end_l4

  l3:
    sub ecx, 1
    inc ebx
    stosb
    cmp ecx, 0
    jne upper
    jmp end_l4

  l4:
    sub ecx, 1
    mov ebx, 0
    stosb
    cmp ecx, 0
    jne upper
    jmp end_l4
  end_l4:

    PRINT_STRING strUpper
    NEWLINE

    ; Letra F ============================================
    NEWLINE
    PRINT_STRING 'Letra F ----- '
    NEWLINE
    mov ecx, PARTIAL_MSG_CONCAT_SIZE
    mov esi, strConcat
    
  printChar:
    lodsb
    PRINT_CHAR eax
    PRINT_STRING "->"
    sub eax,MIN_A_POS_ASCII
    PRINT_DEC 1,eax
    NEWLINE
    sub ecx, 1
    cmp ecx, 0 ; Distancia mt grande para o loop
    jne printChar

    ; Letra G ============================================

    NEWLINE
    PRINT_STRING 'Letra G ----- '
    NEWLINE
    mov ecx, PARTIAL_MSG_CONCAT_SIZE
    mov esi, strConcat
    mov ebx, 0
    
    ; Load numbers in array
  loadNumVec:
    lodsb
    sub eax, MIN_A_POS_ASCII
    mov [letterNum+ebx], eax
    inc ebx
    dec ecx
    cmp ecx, 0
    jne loadNumVec
    
    ; Make bubble sort
    
    mov edx, PARTIAL_MSG_CONCAT_SIZE-1
    
  bubbleOuter:
    mov ecx, PARTIAL_MSG_CONCAT_SIZE-1
    mov esi, letterNum
    bubbleInner:
        mov al, [esi]
        cmp al, [esi+1]
        jl incre
        xchg al, [esi+1]
        mov [esi], al
        
        incre:
            inc esi
            loop bubbleInner
    dec edx
    jnz bubbleOuter
    
    ; Print the numbers
    mov ecx, PARTIAL_MSG_CONCAT_SIZE-1
    mov eax, letterNum
    mov ebx, 0
    
  printLetterNum:
    PRINT_DEC 1, [eax]
    add ebx, [eax]
    NEWLINE
    inc eax
    dec ecx
    cmp ecx, 0
    jne printLetterNum

    NEWLINE
    PRINT_STRING 'Média --- '
    
  calcMedia:
    mov eax, ebx
    mov ebx, PARTIAL_MSG_CONCAT_SIZE
    div ebx
    PRINT_DEC 1, ebx

    ; FINISH CODE ========================================

    mov ecx, 0
    mov eax, 1          ; Return
    mov ebx, 0          ; | <- return code
    int 80h             ; \
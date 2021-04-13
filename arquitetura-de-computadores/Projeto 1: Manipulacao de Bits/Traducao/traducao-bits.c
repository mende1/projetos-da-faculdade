/*
 * CS:APP Data Lab
 *
 * <Por favor coloque seu nome e identificador aqui>
 *
 * bits.c - Aquivo com as suas soluções.
 *          Este é o arquivo que você enviará ao professor.
 *          (Obs: Esta é a tradução. O arquivo correto é o bits.c)
 *
 * AVISO: Não inclua o <stdio.h>; Ele confunde o compilador dlc.
 * Você ainda poderá utilizar o prinft para fins de debugar o código
 * sem incluir o <stdio.h>, embora você possa receber um aviso do compilador.
 * Geralmente, não é uma boa prática ignorar avisos do compilador, mas neste 
 * caso tudo bem.
 */

#ifndef COMMON_H
#include "common.h"
#endif

#if 0
/*
 * Instruções para os alunos:
 *
 * PASSO 1: Leia com atenção as instruções a seguir.
 */

Você dará suas soluções para os desafios editando
as funções deste arquivo.

REGRAS PARA OS CÓDIGOS:

  Substitua o "return" em cada função por uma ou mais linhas de código
  em C que implementa a função. Seu código deve seguir o seguinte estilo:
 
  int Funct(arg1, arg2, ...) {
      /* breve descrição de como funciona sua implementação */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Cada"Expr" é uma expressão que utiliza APENAS o seguinte:
  1. Constantes inteiras de 0 até 255 (0xFF). Você não pode
     usar constantes grandes como 0xffffffff.
     Porém, você pode combinar constantes de valores maiores
     que 255 ou menores que 0. ex: 250 + 250 = 500, desde que
     o operador que você utilizar para combinar as constantes 
     seja listado como "legal" acima da função que você está 
     implementando.
  2. Argumentos de funções e variáveis locais (sem variáveis globais).
  3. Quaisquer operadores listados como "legais" acima da função que você
     está implementando.
  4. Formas abreviadas de operadores "legais" (ex. você pode usar ++ 
     e += se + for legal)

  Alguns dos problemas restringem ainda mais o conjunto dos operadores permitidos. 
  Cada "Expr" deve consistir de multiplos operadores. Você não está restrito a usar
  apenas um operador por linha.

  Você é expressamente proibido de:
  1. Usar qualquer estrutura de controle como if, do, while, for, switch, etc.
  2. Definir ou usar quaisquer macros.
  3. Definir qualquer outra função neste arquivo.
  4. Chamar qualquer função.
  5. Usar qualquer outro operador, como &&, ||, -, or ?:
  6. Usar qualquer forma de conversão.
  7. Usar qualquer tipo de dado diferente de int. Isso implica que 
     você não pode usar vetores, structs, ou unions.


  Você deve assumir que sua máquina:
  1. Usa complemento de 2, representação de 32 bits para inteiros.
  2. Performa shifts para direita aritmeticamente.
  3. Tem comportamento imprevisível se o shift for de menos que 0 ou
     mais que 31.

EXEMPLOS DE ESTILO DE CÓDIGO ACEITOS:
  /*
   * pow2plus1 - retorna 2^x + 1, onde 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* explora a habilidade do shift de computar potências de 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - retorna 2^x + 4, onde 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* explora a habilidade do shift de computar potências de 2 */
     int resultado = (1 << x);
     resultado += 4;
     return resultado;
  }


NOTAS:
  1. Use o compilador dlc para checar a legalidade de suas soluções.
  2. Cada função tem um número máximo de operações (inteiras, lógicas,
     ou comparações) que você poderá usar para implementá-la. O número  
     máximo é checado pelo arquivo dlc.
     Note que atribuição ('=') não é contado; você pode usar quantas
     quiser sem ser penalizado.
  3. Use o arquivo btest para testar se as suas soluções são possíveis.
  4. O número máximo de operadores para cada função é dado no comentário
     acima de cada uma delas. Se houver qualquer inconsistência entre o 
     o número máximo no artigo e neste arquivo, considere este arquivo a
     fonte autoritária.
  5. Escreva comentários para suas funções. Eles não serão avaliados, mas
     é uma boa prática comentar e pode ajudar a debugar o seu código. Veja
     o exemplo acima para perceber como um comentário deve ser feito.

/*
 * PASSO 2: Modifique as funções a seguir de acordo com as regras.
 *
 *   IMPORTANTE. PARA EVITAR SURPRESAS NA NOTA:
 *   1. Use o compilador dlc para checar se as suas soluções estão de
        acordo com as regras.
 */
#endif

/* 
 * bitXor - x^y usando apenas ~ e & 
 *   Exemplo: bitXor(4, 5) = 1
 *   Operadores legais: ~ &
 *   Máx de operadores: 14
 *   Avaliação: 1
 */
int bitXor(int x, int y) {
  return 2;
}

/* 
 * allEvenBits - retorna 1 se todos os bits de números pares são 1
 *   onde os bits são enumerados de 0 (menos significante) a 31 (mais significante)
 *   Exemplos: allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Operadores legais: ! ~ & ^ | + << >>
 *   Máx de operadores: 12
 *   Avaliação: 2
 */
int allEvenBits(int x) {
  return 2;
}

/* 
 * logicalShift - desloca x para a direita em n casas, usando shift lógico
 *   Pode assumir que 0 <= n <= 31
 *   Exemplos: logicalShift(0x87654321,4) = 0x08765432
 *   Operadores legais: ! ~ & ^ | + << >>
 *   Máx de operadores: 20
 *   Avaliação: 3 
 */
int logicalShift(int x, int n) {
    return 2;
}

/* 
 * logicalNeg - implementa o operador !, usando todos os 
 *              operadores legais, exceto !
 *   Exemplos: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Operadores legais: ~ & ^ | + << >>
 *   Máx de operadores: 12
 *   Avaliação: 4 
 */
int logicalNeg(int x) {
  return 2;
}

/* 
 * TMax - retorna o maior inteiro complemento de 2
 *   Operadores legais: ! ~ & ^ | + << >>
 *   Máx de operadores: 4
 *   Avaliação: 1
 */
int tmax(void) {
  return 2;
}

/* 
 * twosBits - retorna 1 se "x" pode ser representado como
 *  um complemento de 2 de "n" bits
 *   1 <= n <= 32
 *   Exemplos: twosBits(5,3) = 0, twosBits(-4,3) = 1
 *   Operadores legais: ! ~ & ^ | + << >>
 *   Máx de operadores: 15
 *   Avaliação: 2
 */
int twosBits(int x, int n) {
  return 2;
}



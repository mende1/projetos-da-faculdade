#include <iostream>
#include <vector>
#include <string>

// importação das constantes definidas para o escopo do problema
#include "sortAlg.h"

using namespace std;

// função de ordenação usando o método da contagem (ordenação em tempo linear)
// ela irá ordenar todo o vetor de placas de acordo com o digito informado;
// 
// A ordenação por contagem assume que cada item do vetor é um número inteiro de 0...K
// Ele é em tempo linear pois não faz comparações entre valores como em outras ordenações mais comuns
// Para fazer ordenação ele vai contar quantas vezes cada inteiro aparece no vetor e armazenar em
// um vetor auxiliar de contagem, um contador, no indicie de mesmo valor do inteiro
//
// Desse jeito, conseguimos ordenar sem comparações, apenas por contagem, com uma manipulação de valores aqui
// e outra ali, conseguimos fazer essa ordenação tão eficiente, que tem complexidade O(n+K), quando k = O(n),
// o algoiritmo será melhor ainda e custará apenas O(n);
void countingSort (vector<string>* vetor, int posicao) {
    
    int contador[RANGE];            // declarando um vetor para auxiliar na contagem
    vector<string> auxiliar;        // declarando um vetor de strings para auxiliar na manipulação das placas

    for (int i=0; i < TAMANHO; i++) {
        string aux = "0000000";
        auxiliar.push_back(aux);        // populando todo o vetor auxiliar com "0000000" apenas para definir as posições
    }

    for (unsigned int i=0; i < RANGE; i++) {
        contador[i] = 0;
    }                                   // populando o vetor contador com zeros para contagem iniciar

    for (unsigned int i=0; i < TAMANHO; i++) {
        
        int caracter = ((*vetor)[i].at(posicao)-48);    // este caracter é o digito (posicao) requisitado na string
        contador[caracter]++;                           // e de acordo ele aparece, fazemos a contagem no contador
    }

    for (unsigned int i=1; i < RANGE; i++) {
        contador[i] = contador[i] + contador[i-1];      // aqui somammos todos os valores dos contadores para
    }                                                   // facilitar na manipulação do vetor mais pra frente

    for (int i=TAMANHO-1; i > -1; i--) {
        int caracter = ((*vetor)[i].at(posicao)-48);

        contador[caracter]--;                           // para cada número que foi contado, reduzimos em 1
        auxiliar[contador[caracter]] = (*vetor)[i];     // e então ele ordena o vetor de acordo com o digito indicado
    }

    for (unsigned int i=0; i < TAMANHO; i++) {      
        (*vetor)[i] = auxiliar[i];                      // atribuimos nosso vetor original o vetor auxiliar já ordenado
    }
}

// Função para ordenar o vetor das placas em forma (quase) linear;
// É uma ordenação lexicográfica (ou seja) ordena caracteres;
// Ele vai ordenar o vetor de acordo com cada digito das strings
// indo do digito menos significativo (da direita) até o mais
// significativo (da esquerda). Ele vai usar como método auxiliar
// a ordenação por contagem (counting sort) também linear; 
vector<string> radixSort (vector<string> vetor) {
    for (int posicao=6; posicao >= 0 ; posicao--) {     // do digito menos significativo até o mais
        countingSort(&vetor, posicao);              // passando o vetor e o digito desejado para o counting sort
    }
    
    return vetor;               // retornando este vetor já ordenado
}
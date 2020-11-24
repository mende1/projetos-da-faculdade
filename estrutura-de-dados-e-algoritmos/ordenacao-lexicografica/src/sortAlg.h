#ifndef _ALGORITMOS_DE_ORDENACAO_
#define _ALGORITMOS_DE_ORDENACAO_

    #define TAMANHO 100000          // tamanho total do vetor e a quantidade de placas
    #define RANGE 43                
    /* RANGE de 43, indica o intervado dos caracteres que vão ser analisados;
    ** Vai de acordo com a tabela ascii. Para esse problema só vão ser analisados
    ** os números de 0 - 9 e as letras maiúsculas A - Z, o número zero tem valor
    ** decimal na tabela ascii de 048, já o caracter Z é 090, com um total de 42 de intervalo
    ** Para considerar de 0 até 42 é mais interessante para contagem de vetores que começam do zero
    ** Caso fosse considerar até o 90, teria que considerar do 000 até o 090, ocupando mais memória;
    ** 
    ** A solução foi pegar o valor do caractere, e diminuir por 48 unidades, assim conseguimos
    ** apenas o intervalo de 0 a 42, adicionado 1, para ficar 43 e ter um espaço a mais e evitar
    ** o Segmentation Fault
    */

    using namespace std;
        
        void countingSort (vector<string>* vetor, int posicao);

        vector<string> radixSort (vector<string> vetor);

#endif // _ALGORITMOS_DE_ORDENACAO_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "sortAlg.h"

using namespace std;

/*  GERAÇÃO DE PLACAS ALEATÓRIAS E NÃO REPETIDAS;
**
**  Vamos gerar gerar 3 números e 4 letras aleatórios
**  e então adicionando pouco a pouco a um string auxiliar
**  e assim imprimimos essa string em uma linha do arquivo de texto
**
**  A quantidade de placas geradas é definida pela constante TAMANHO, declarada no "sortAlgs.h"
*/
int main () {

    srand ( time(NULL) );

    ofstream file;      // função de escrita em arquivo da biblioteca fstream
    string nameFile = "database/placas.txt";

    file.open(nameFile);            // abertura do arquivo para escrita

    vector<string> vetor;           // vetor para guardar as placas geradas e verificar se não há repetição

    cout << endl << "   [ Gerando placas aleatórias ]\n" << endl;

    for (int i=0; i<TAMANHO; i++) {

        char letra[7];          // aqui é declarado o vetor de char de tamanho 7, de acordo com as placas
        string aux;             // string para auxiliar na manipulação dos caracteres

        for (int j=0; j<7; j++) {       // nesta repetição, é analisado o padrão da placa ABC1D23
            if (j == 3) {
                letra[j] = (rand() % 10) + 48;      // número (0-9) aleatório na posição 3
            } else if (j == 5) {
                letra[j] = (rand() % 10) + 48;      // número (0-9) aleatório na posição 5
            } else if (j==6) {
                letra[j] = (rand() % 10) + 48;      // número (0-9) aleatório na posição 6
            } else {
                letra[j] = (rand() % 26) + 65;      // letra (A-Z) aleatória nas posições 0, 1, 2, 4
            }
        }

        for (int j=0; j<7; j++) {
            aux.push_back(letra[j]);        // adicionado char por char na string auxiliar
        }

        bool confirm = true;
        for (unsigned int k=0; k < i; k++) {        // código para analisar os vetores anteriores
            if (aux == vetor[k]) {                  // e verificar se não há outras placas repetidas
                confirm = false;                    // caso tenha, volta uma repetição e será gerado
                break;                              // uma outra placa. É esta verificação que faz o
            }                                       // gerador ser tão lento
        }

        if (confirm) {
            for (int j=0; j<7; j++) {
                file << letra[j];                   // imprimir letra por letra na linha
            }                                       // e então uma quebra de linha para
            file << "\n";                           // a próxima placa

            vetor.push_back(aux);                   // finalmente adicionando a placa ao vetor
        
        } else --i;

        if (i % 10000 == 0 && i) {
            cout << "Gerados " << i << " placas..." << endl;    // apenas para gerar informação de
        }                                                       // quantas placas foram geradas
    }

    cout << endl<< "   [ Sucesso! Gerados " << TAMANHO << " placas. ]\n" <<endl;

    file.close();                                   // fechamento do arquivo
}
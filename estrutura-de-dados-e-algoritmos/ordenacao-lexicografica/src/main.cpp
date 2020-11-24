#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// importação dos algoritmos de ordenação
#include "sortAlg.h"

using namespace std;

    // Função para imprimir um vetor em um arquivo de texto
void imprimirPlacas (vector<string> vetor, string nameFile) {
    
    ofstream file;          //abrindo um arquivo com função de escrita

    file.open(nameFile);

    for (int i=0; i < TAMANHO; i++) {
        for (int j=0; j<7; j++) {
            file << vetor[i].at(j);          // imprimindo letra por letra do vetor
        }                                    // para formar as placas no padrão correto
        file << "\n";                        // imprimindo uma quebra de linha para próxima placa
    }

    file.close();
}

    // Função para ler um arquivo de texto, e guardar
    // cada linha em uma posição de um vetor qualquer
vector<string> lerDados (vector<string> vetor, string nameFile) {
    
    ifstream file;          // abrindo um arquivo com função de leitura
    
    file.open(nameFile);

    string aux;
    for (unsigned int i=0; i < TAMANHO; i++) {
        getline(file, aux);                         // pegando a string de cada linha e
                                                    // armazenando na variável auxiliar
        vetor.push_back(aux);   // adicionando a variável auxiliar ao vetor desejado
    }
    file.close();

    return vetor;
}

int main() {
    
    vector<string> vetor;               // declarando o vetor principal que vai ser preenchido e ordenado

    vetor = lerDados(vetor, "database/placas.txt");     // leitura dos dados e armazenando no vetor

    vetor = radixSort(vetor);                           // ordenando através do Radix sort

    imprimirPlacas(vetor, "database/sortPlacas.txt");   // imprimindo o vetor ordenado no arquivo de texto
}
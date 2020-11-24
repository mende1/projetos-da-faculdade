#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "tadVetorDin.h"

// ***********************************************
// ***********************************************
// ***********************************************

int main(int argc, char** argv) {

unsigned int numElementos;  

	if (argc > 1)
		numElementos = atoi(argv[1]);
	else
		numElementos = 10;

	cVetorDin vet(numElementos);

	int k=100;

	while (vet.posicoesLives() > 0) { 
		if (!vet.InsereElem(k) ) {
			std::cout << "Capacidade do vetor estourada\n";
			return -1;
			}
		k -= 10;
		}

	std::cout << vet << std::endl;
	  	
	k = 0;
	while ( (k < 20) && (vet.tamanho() > 0) ) {
		int chave = rand() % 100;
		if ( !vet.RemoveElem(chave) ) 
			std::cout << "Chave " << chave << " nao encontrada\n";
		else
			std::cout << "Chave " << chave << " encontrada\n";
		k++;
		}

	std::cout << vet << std::endl;
	  	
}

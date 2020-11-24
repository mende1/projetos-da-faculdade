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

	while (vet.posicoesLives() > 0) 
		if (!vet.InsereElem(rand() % numElementos*10) ) {
			std::cout << "Capacidade do vetor estourada\n";
			return -1;
			}

	std::cout << vet;

	if (!vet.InsereElem(rand() % numElementos*10) ) 
		std::cout << "Capacidade do vetor estourada\n";
}

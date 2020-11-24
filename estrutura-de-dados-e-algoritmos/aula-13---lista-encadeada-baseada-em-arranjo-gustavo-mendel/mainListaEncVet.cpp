#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "tadListEncVet.h"

// ***********************************************
// ***********************************************
// ***********************************************

int main(int argc, char** argv) {

unsigned int numElementos;  

	if (argc > 1)
		numElementos = atoi(argv[1]);
	else
		numElementos = 10;

	cListaEncVet vet(numElementos);

	vet.printVetor();
	std::cout << vet << std::endl;

	int k=100;

	while (vet.posicoesLivres() > 0) { 
		if (!vet.InsereElem(k) ) {
			std::cout << "Capacidade da lista estourada\n";
			return -1;
			}
		k -= 10;
		}

	vet.printVetor();
	std::cout << vet << std::endl;
	  	
	int chave = 50;
	if ( !vet.RemoveElem(chave) ) 
		std::cout << "Chave " << chave << " nao encontrada\n";
	else
		std::cout << "Chave " << chave << " encontrada\n";

	vet.printVetor();
	std::cout << vet << std::endl;
	  	
	chave = 100;
	if ( !vet.RemoveElem(chave) ) 
		std::cout << "Chave " << chave << " nao encontrada\n";
	else
		std::cout << "Chave " << chave << " encontrada\n";

	vet.printVetor();
	std::cout << vet << std::endl;
	  	
	chave = 10;
	if ( !vet.RemoveElem(chave) ) 
		std::cout << "Chave " << chave << " nao encontrada\n";
	else
		std::cout << "Chave " << chave << " encontrada\n";

	vet.printVetor();
	std::cout << vet << std::endl;
	  		  	
	if (!vet.InsereElem(75) ) {
		std::cout << "Capacidade do vetor estourada\n";
		}
	if (!vet.InsereElem(15) ) {
		std::cout << "Capacidade do vetor estourada\n";
		}
	if (!vet.InsereElem(25) ) {
		std::cout << "Capacidade do vetor estourada\n";
		}
		
	vet.printVetor();
	std::cout << vet << std::endl;
	  		  	
}

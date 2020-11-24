#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "tadListaEncDin.h"

// ***********************************************
// ***********************************************
// ***********************************************

int main(int argc, char** argv) {

	cListaEncDin LSE;

	std::cout << LSE << std::endl;

	int k=100;

	while (LSE.tamanho() < 10) { 
		if (!LSE.InsereElem(k) ) {
			std::cout << "Erro na alocacao de novo no para LSE\n";
			return -1;
			}
		k -= 10;
		}

	std::cout << LSE << std::endl;
	  	
	int chave = 50;
	if ( !LSE.RemoveElem(chave) ) 
		std::cout << "Chave " << chave << " nao encontrada\n";
	else
		std::cout << "Chave " << chave << " encontrada\n";

	std::cout << LSE << std::endl;
	  	
	chave = 100;
	if ( !LSE.RemoveElem(chave) ) 
		std::cout << "Chave " << chave << " nao encontrada\n";
	else
		std::cout << "Chave " << chave << " encontrada\n";

	std::cout << LSE << std::endl;
	  	
	chave = 10;
	if ( !LSE.RemoveElem(chave) ) 
		std::cout << "Chave " << chave << " nao encontrada\n";
	else
		std::cout << "Chave " << chave << " encontrada\n";

	std::cout << LSE << std::endl;
	  		  	
	if (!LSE.InsereElem(75) ) {
		std::cout << "Capacidade do LSE estourada\n";
		}
	if (!LSE.InsereElem(15) ) {
		std::cout << "Capacidade do LSE estourada\n";
		}
	if (!LSE.InsereElem(25) ) {
		std::cout << "Capacidade do LSE estourada\n";
		}
		
	std::cout << LSE << std::endl;
	  		  	
}

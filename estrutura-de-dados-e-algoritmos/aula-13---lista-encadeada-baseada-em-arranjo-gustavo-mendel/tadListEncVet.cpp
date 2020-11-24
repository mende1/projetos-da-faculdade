/* Tipos Abstratos e Registros */ 

#include<iostream>

#include "tadListEncVet.h"

// ******************************************************
// ***
// ******************************************************
cListaEncVet::cListaEncVet()  { 
	vet 	= NULL;
	numElem = 0;
	inicio 	= -1; 
}

// ******************************************************
// ***
// ******************************************************
cListaEncVet::cListaEncVet(int tam)  { 

	std::cout << tam << std::endl;

	vet 	= new cNo[tam];

	numElem 	= tam;
	inicio 		= -1;
	posLivres 	= tam;

	for (int i = 0 ; i < numElem ; i++) 
		vet[i].setProx(i);
}


// ******************************************************
// ***
// ******************************************************
cListaEncVet::cListaEncVet(const cListaEncVet &v)  { 

	vet = new cNo[v.numElem];

	std::cout << vet << std::endl;

	for (int i = 0 ; i < v.numElem ; i++) {
		vet[i].setDado(v.vet[i].getDado());    
		vet[i].setProx(v.vet[i].getProx());    
		}

	numElem 	= v.numElem;
	inicio 		= v.inicio;
	posLivres 	= v.posLivres;
}

// ******************************************************
// ***
// ******************************************************
cListaEncVet::~cListaEncVet() { 

	if (vet != NULL) 
		delete [] vet;
}

// ******************************************************
// ***
// ******************************************************
bool cListaEncVet::buscaPosicaoLivre(int& p)  { 

	return false;
}

// ******************************************************
// ***
// ******************************************************
int cListaEncVet::buscaUltimaPosicao()  { 

	return -1;
}

// ******************************************************
// ***
// ******************************************************
bool cListaEncVet::InsereElem(int dado)  { 

  int pos;

	if ( !buscaPosicaoLivre(pos) )  // percorre o vetor 
		return false;

	vet[pos].setDado(dado);
	vet[pos].setProx(-1);

	int ultPos = buscaUltimaPosicao();  // percorre a lista

	if ( ultPos == -1)
		inicio = pos;
	else 
		vet[ultPos].setProx(pos);

	posLivres--;

	return true;
}

// ******************************************************
// ***
// ******************************************************
bool cListaEncVet::BuscaElem(int chave, int& pos)  { 

	return false;
}

// ******************************************************
// ***
// ******************************************************
bool cListaEncVet::BuscaElem(int chave, int& pos, int& ant)  { 

	return false;
}

// ******************************************************
// ***
// ******************************************************
bool cListaEncVet::RemoveElem(int chave)  {  

	return false;
}

// ******************************************************
// ***
// ******************************************************
int cListaEncVet::posicoesLivres() {  

	return (posLivres);
}

// ******************************************************
// ***
// ******************************************************
int cListaEncVet::tamanho() {

	return (numElem);
}

// ******************************************************
// ***
// ******************************************************
void cListaEncVet::printVetor() { 

	std::cout << "===================================" << std::endl;
	std::cout << "Numero de elementos = " << numElem << std::endl;
	std::cout << "Inicio = " << inicio << std::endl;
	std::cout << "Posicoes Livres = " << posLivres << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	int count=0;

	while (count < numElem) { 
		std::cout 	<< "[ " << count
					<<  " ] = ( " << vet[count].getDado() 
					<<  " , " << vet[count].getProx() << " ) "
					<< std::endl;
		count++;
		}

	std::cout << "===================================" << std::endl;

}

// ******************************************************
// ***
// ******************************************************
std::ostream &operator<<( std::ostream &output, const cListaEncVet &v ) { 

	output << "===================================" << std::endl;
	output << "Endereco do vetor base = " << v.vet << std::endl;
	output << "Numero de elementos = " << v.numElem << std::endl;
	output << "Posicoes Livres = " << v.posLivres << std::endl;
	output << "-----------------------------------" << std::endl;

	if (v.inicio == -1)
		output << " **** Lista Vazio ****" << std::endl;
	else {
		int noCor = v.inicio;
		int count=0;

		while (noCor != -1) { 
			output << "[ " << count++ <<  " ] = " << v.vet[noCor].getDado() << std::endl;
			noCor = v.vet[noCor].getProx();
			}
		}

	output << "===================================" << std::endl;

	return output;            
}
				

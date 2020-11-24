/* Tipos Abstratos e Registros */ 

#include<iostream>

#include "tadVetorDin.h"

// ******************************************************
// ***
// ******************************************************
cVetorDin::cVetorDin()  { 
	vet		= NULL;
	numElem = 0;
	ultPos 	= -1; 
}

// ******************************************************
// ***
// ******************************************************
cVetorDin::cVetorDin(int tam)  { 

	vet 	= new int[tam];
	numElem = tam;
	ultPos 	= -1;
}


// ******************************************************
// ***
// ******************************************************
cVetorDin::cVetorDin(const cVetorDin &v)  { 

	vet = new int[v.numElem];

	for (int i = 0 ; i < v.ultPos ; i++)
		vet[i] = v.vet[i];    

	numElem = v.numElem;
	ultPos 	= v.ultPos;
}

// ******************************************************
// ***
// ******************************************************
cVetorDin::~cVetorDin() { 

	if (vet != NULL)
		delete vet;
}

// ******************************************************
// ***
// ******************************************************
bool cVetorDin::InsereElem(int dado)  { 

	if (ultPos == (numElem-1) )
		return false;

	vet[++ultPos] = dado;

	return true;
}

// ******************************************************
// ***
// ******************************************************
bool cVetorDin::BuscaElem(int chave, int& pos)  { 

	for (int i = 0 ; i <= ultPos ; i++)
		if (vet[i] == chave) {
			pos = i;
			return true;
			}

	return false;
	}

// ******************************************************
// ***
// ******************************************************
bool cVetorDin::RemoveElem(int chave)  {  

	int p;

	if (!BuscaElem(chave, p)) 
		return false;

	for (int i = p ; i < ultPos ; i++)  
		vet[i] = vet[i+1];

	ultPos--;

	return true;
}

// ******************************************************
// ***
// ******************************************************
int cVetorDin::posicoesLives() {

	return (numElem - (ultPos+1));
}

// ******************************************************
// ***
// ******************************************************
int cVetorDin::tamanho() {

	return (numElem);
}

// ******************************************************
// ***
// ******************************************************
std::ostream &operator<<( std::ostream &output, const cVetorDin &v ) { 

	output << "===================================" << std::endl;
	output << "Endereco do vetor = " << v.vet << std::endl;
	output << "Numero de elementos = " << v.numElem << std::endl;
	output << "Ultima posicao ocupada = " << v.ultPos << std::endl;
	output << "-----------------------------------" << std::endl;

	for (int k = 0 ; k <= v.ultPos ; k++)
		output << "[ " << k <<  " ] = " << v.vet[k] << std::endl;

	output << "===================================" << std::endl;

	return output;            
}

// ******************************************************
// ***
// ******************************************************
std::istream &operator>>( std::istream  &input, cVetorDin &v ) { 

	for (int k = 0 ; k <= v.ultPos ; k++)
		input >> v.vet[k];

	return input;            
}
				

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

	return false;
}

// ******************************************************
// ***
// ******************************************************
bool cVetorDin::RemoveElem(int chave)  { 

	return false;
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
	output << "Numero de elementos = " << v.numElem << std::endl;
	output << "Ultima posicao livre = " << v.ultPos << std::endl;
	output << "-----------------------------------" << std::endl;

	for (int k = 0 ; k < v.numElem ; k++)
		output << "[ " << k <<  " ] = " << v.vet[k] << std::endl;

	output << "===================================" << std::endl;

	return output;            
}

// ******************************************************
// ***
// ******************************************************
std::istream &operator>>( std::istream  &input, cVetorDin &v ) { 

	for (int k = 0 ; k < v.numElem ; k++)
		input >> v.vet[k];

	return input;            
}
				

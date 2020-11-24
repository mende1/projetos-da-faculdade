/* Tipos Abstratos e Registros */ 

#include<iostream>

#include "tadListaEncDin.h"

// ******************************************************
// ***
// ******************************************************
cListaEncDin::cListaEncDin()  { 
	inicio	= NULL;
	numElem = 0;
}

// ******************************************************
// ***
// ******************************************************
cListaEncDin::cListaEncDin(const cListaEncDin &v)  { 


}

// ******************************************************
// ***
// ******************************************************
cListaEncDin::~cListaEncDin() { 


}

// ******************************************************
// ***
// ******************************************************
cNo* cListaEncDin::buscaUltimaPosicao()  { 

	return NULL;

}

// ******************************************************
// ***
// ******************************************************
bool cListaEncDin::InsereElem(int dado)  { 

	return false;
}

// ******************************************************
// ***
// ******************************************************
bool cListaEncDin::BuscaElem(int chave, cNo** no)  { 


	return false;
}

// ******************************************************
// ***
// ******************************************************
bool cListaEncDin::BuscaElem(int chave, cNo** noAnterior, cNo** noCorrente)  { 

	return false;
}

// ******************************************************
// ***
// ******************************************************
bool cListaEncDin::RemoveElem(int chave)  {  

	return false;
}

// ******************************************************
// ***
// ******************************************************
int cListaEncDin::tamanho() {

	return (numElem);
}

// ******************************************************
// ***
// ******************************************************
std::ostream &operator<<( std::ostream &output, const cListaEncDin &l ) { 

	output << "===================================" << std::endl;
	output << "Endereco do inicio = " <<  l.inicio << std::endl;
	output << "Numero de elementos = " << l.numElem << std::endl;
	output << "-----------------------------------" << std::endl;

	if (l.inicio == NULL)
		output << " **** Lista Vazia ****" << std::endl;
	else {
		cNo* noCorrente = l.inicio;
		int count=0;

		while (noCorrente != NULL) { 
			output << "[ " << count++ <<  " ] = " << noCorrente->getDado() << std::endl;
			noCorrente = noCorrente->getProx();
			}
		}

	output << "===================================" << std::endl;

	return output;            
}
				

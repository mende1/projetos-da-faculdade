/* Classe data */ 

#include<iostream>

#include "tadNo.h"

class cListaEncDin	{ 

	private:
		cNo* inicio;    	// indica a primeira posicao da lista 
  		int  numElem;   	// Total de posicoes alocadas

		cNo*  buscaUltimaPosicao();

	public:	
		cListaEncDin();

		cListaEncDin(const cListaEncDin &l);

		~cListaEncDin();

		bool InsereElem(int dado);

		bool BuscaElem(int dado, cNo** no);

		bool BuscaElem(int dado, cNo** noAnterior, cNo** noCorrente);

		bool RemoveElem(int dado);

		int tamanho();

		friend std::ostream &operator<<( std::ostream &output, const cListaEncDin &l);

};


/* Classe data */ 

#include<iostream>

#include "tadNo.h"

class cListaEncVet	{ 

	private:
		cNo* vet;		    // espaço de memoria alocado dinamicamente
  		int  numElem;   	// Total de posicoes alocadas
		int  inicio;    	// indica a primeira posicao da lista 
		int  posLivres; 	// indica o total de posicoes livres na lista

		bool buscaPosicaoLivre(int& pos);
		int  buscaUltimaPosicao();

	public:	
		cListaEncVet();

		cListaEncVet(int tam);

		cListaEncVet(const cListaEncVet &v);

		~cListaEncVet();

		bool InsereElem(int dado);

		bool BuscaElem(int dado, int& pos);

		bool BuscaElem(int dado, int& pos, int& ant);

		bool RemoveElem(int dado);

		int posicoesLivres();

		int tamanho();

		void printVetor();

		friend std::ostream &operator<<( std::ostream &output, const cListaEncVet &v);
};


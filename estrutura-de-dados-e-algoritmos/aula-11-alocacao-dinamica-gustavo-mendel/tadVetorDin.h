/* Classe data */ 

#include<iostream>

class cVetorDin	{ 

	private:
		int* vet;
		int  numElem;
		int  ultPos;

	public:	
		cVetorDin();

		cVetorDin(int tam);

		cVetorDin(const cVetorDin &v);

		~cVetorDin();

		bool InsereElem(int dado);

		bool BuscaElem(int dado, int& pos);

		bool RemoveElem(int dado);

		int posicoesLives();

		int tamanho();

		friend std::ostream &operator<<( std::ostream &output, const cVetorDin &v);

		friend std::istream &operator>>( std::istream  &input, cVetorDin &v );
};


#include <iostream>
#include <string>

using namespace std;

int main(){

	int n, m, i, j, p;

	cin>>n;

	int pokemon[n];

	for(i=0; i<n; i++){

		cin>>pokemon[i];

	}

	cin>>m;

	int chaves[m];

	for(i=0; i<m; i++)

		cin>>chaves[i];

		int esquerda, direita, meio;
	for(i=0; i<m; i++){

		p = chaves[i];

		esquerda = 0;
		direita = n - 1;

		while(esquerda <= direita){

			meio = (esquerda + direita) / 2;

		if(p < pokemon[meio])

			direita = meio - 1;

		else if(p == pokemon[meio])

			break;

		else

			esquerda = meio	+ 1;

		}

	if(p == pokemon[meio])

		cout<<meio<<endl;

	else

		cout<<"Pokemon nao encontrado!"<<endl;

	}

}

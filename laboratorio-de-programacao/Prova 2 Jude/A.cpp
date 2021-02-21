#include <iostream>
#include <stdlib.h>

using namespace std;

int main () {

	int *inicio, *fim, *meio, *aux;
	int i, tam, n_tam, extra, m;

	cin >> tam;

	inicio = (int*) calloc (tam, sizeof (int));

	for (aux = inicio, i = 0; i < tam; i++, aux++){
		cin >> *aux;
	}

	fim = inicio+(tam-1);

	m = (tam/2);
	meio = inicio+m;

	cout << *inicio << " " << *meio << " " << *fim << endl;

	cin >> extra;

	n_tam = tam + extra;

	inicio = (int*)realloc (inicio, n_tam*sizeof(int));

	for (aux = inicio+tam, i = tam; i < n_tam; i++, aux++){
		cin >> *aux;
	}

	fim = inicio+(n_tam-1);

	m = (n_tam/2);
	meio = inicio+m;

	cout << *inicio << " " << *meio << " " << *fim << endl;

	return 0;
}
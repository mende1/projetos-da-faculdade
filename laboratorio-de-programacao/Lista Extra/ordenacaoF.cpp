#include <iostream>
#include <string>

using namespace std;

int main(){

	int N;

	cin >> N;

	string linguagem[N], auxs;
	double pontuacao[N], aux;

	for (int i=0; i<N; i++) {
		cin >> linguagem[i] >> pontuacao[i];
	}

	int menor_i;

	for (int i=0; i<N-1; i++) {

		menor_i = i;

		for (int j=i+1; j<N; j++) {
			if (pontuacao[j] > pontuacao[menor_i]) {
				menor_i = j;
			}
		}

		auxs = linguagem[i];
		linguagem[i] = linguagem[menor_i];
		linguagem[menor_i] = auxs;

		aux = pontuacao[i];
		pontuacao[i] = pontuacao[menor_i];
		pontuacao[menor_i] = aux;
	}

	for (int i=0; i<N; i++) {
		cout << linguagem[i] << " ";
		cout.precision(1);
		cout << fixed << pontuacao[i] << endl;
	}
}
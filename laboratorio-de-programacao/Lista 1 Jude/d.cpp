#include <iostream>

using namespace std;

int main() {

	int n;

	cin >> n;

	int vet[n];

	for (int i=0; i<n; i++) {
		cin >> vet[i];
	}

	int p = 0;
	int menor_i, aux;

	for (int j=0; j<n-1; j++) {
		menor_i = j;

		for (int i=j+1; i<n; i++) {

			if (vet[i] < vet[menor_i]) {
				menor_i = i;
				p++;
			}
		}

		aux = vet[j];
		vet[j] = vet[menor_i];
		vet[menor_i] = aux;
	}

	if (p) cout << "nao esta ordenado: executou " << p << " permutas" << endl;
	else cout << "esta ordenado: executou 0 permutas" << endl;
}
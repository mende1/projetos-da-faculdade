#include <iostream>
#include <string>

using namespace std;

int main(){

	int N;

	cin >> N;

	cin.ignore();

	string livro[N], auxs;

	int tamanho[N];

	for (int i=0; i<N; i++) {
		getline(cin, livro[i]);

		livro[i].size();
	}

	int menor_i;

	for (int i=0; i<N-1; i++) {
		menor_i = i;

		for (int j=i+1; j<N; j++) {
			if (livro[j] < livro[menor_i]) {
				menor_i = j;
			}
		}

		auxs = livro[menor_i];
		livro[menor_i] = livro[i];
		livro[i] = auxs;
	}

	for (int i=0; i<N; i++) {
		cout << livro[i] << endl;
	}
}
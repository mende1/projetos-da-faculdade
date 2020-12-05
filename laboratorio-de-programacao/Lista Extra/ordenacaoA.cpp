#include <iostream>
#include <string>

using namespace std;

int main(){

	int N;

	cin >> N;

	int milhao[N];

	for (int i=0; i<N; i++) {
		cin >> milhao[i];
	}

	int menor_i, aux;

	for (int i=0; i<N; i++) {
		menor_i = i;

		for (int j=i+1; j<N; j++) {
			if (milhao[j] < milhao[menor_i]) {
				menor_i = j;
			}
		}

		aux = milhao[i];
		milhao[i] = milhao[menor_i];
		milhao[menor_i] = aux;
	}

	cout << milhao[N/2] << endl;
}
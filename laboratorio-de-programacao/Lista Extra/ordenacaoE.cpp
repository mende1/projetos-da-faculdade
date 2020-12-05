#include <iostream>
#include <string>

using namespace std;

int main(){

	int N;

	cin >> N;

	int boletim[3][N];
	int candidatos[N] = { 0 };

	for (int i=0; i<3; i++) {
		for (int j=0; j<N; j++) {
			cin >> boletim[i][j];
		}
	}

	for (int i=0; i<3; i++) {
		for (int j=0; j<N; j++) {
			candidatos[j] += boletim[i][j];
		}
	}

	int menor_i, aux;

	for (int i=0; i<N-1; i++) {

		menor_i = i;

		for (int j=i+1; j<N; j++) {

			if (candidatos[j] < candidatos[menor_i]) {
				menor_i = j;
			}
		}

		aux = candidatos[i];
		candidatos[i] = candidatos[menor_i];
		candidatos[menor_i] = aux;
	}

	for (int i=0; i<N; i++) {
		cout << candidatos[i] << endl;
	}
}
#include <iostream>

using namespace std;

int main() {

	int n, p;

	cin >> n >> p;

	int Fibo[n];

	Fibo[0] = 0;
	Fibo[1] = 1;

	for (int i=2; i < n; i++) {
		Fibo[i] = Fibo[i-1] + Fibo[i-2];
	}

	int esq = 0;
	int dir = n - 1;
	int meio;

	while (esq <= dir) {

		meio = (esq+dir)/2;

		if (p < Fibo[meio]) {
			dir = meio - 1;

		} else if (p == Fibo[meio]) {
			break;
		
		} else {
			esq = meio + 1;
		}
	}

	if (Fibo[meio] == p) {
		cout << p << " esta na posicao " << meio + 1 << endl;
	} else {
		cout << p << " nao existe" << endl;
	}
}
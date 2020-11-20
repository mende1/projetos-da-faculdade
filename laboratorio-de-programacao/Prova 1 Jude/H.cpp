#include <iostream>

using namespace std;

int main() {

	int n = 3;

	int mat[n][n];

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> mat[i][j];
		}
	}

	int linhaMagica[n] = {0}, colunaMagica[n] = {0}, diagMagica[2] = {0};

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			linhaMagica[i] += mat[i][j];
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			colunaMagica[j] += mat[i][j];
		}
	}

	for (int i=0; i<n; i++) {
		diagMagica[0] += mat[i][i];
	}

	int k = 2;

	for (int i=0; i<n; i++) {
		diagMagica[1] += mat[i][k--];
	}

	int ehLinMag = 1, ehColMag = 1, ehDiaMag = 1;

	for (int i=0; i<n-1; i++) {
		if (linhaMagica[i] != linhaMagica[i+1])
			ehLinMag = 0;
	}

	for (int i=0; i<n-1; i++) {
		if (colunaMagica[i] != colunaMagica[i+1])
			ehColMag = 0;
	}

	if (diagMagica[0] != diagMagica[1])
		ehDiaMag = 0;

	if (ehDiaMag && ehColMag && ehLinMag)
		cout << "eh um quadrado magico" << endl;

	else 
		cout << "nao eh um quadrado magico" << endl;
}
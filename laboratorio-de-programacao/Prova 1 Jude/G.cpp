#include <iostream>

using namespace std;

int main() {

	int l, c;

	cin >> l >> c;

	int cadeira[l][c];

	for (int i=0; i<l; i++) {
		for (int j=0; j<c; j++) {
			cin >> cadeira[i][j];
		}
	}

	for (int i=0; i<l; i++) {
		for (int j=0; j<c-1; j++) {
			
			if (cadeira[i][j] == cadeira[i][j+1] && cadeira[i][j] == 0) {
				
				cout << "Fileira: " << i+1 << endl;
				cout << "Assentos: " << j+1 << " e " << j+2 << endl;
			}
		}
	}
}
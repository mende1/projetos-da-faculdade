#include <iostream>

using namespace std;

int main() {

	char m;
	int carvao;
	int ouro;
	int diamante;

	carvao = ouro = diamante = 0; 

	while (cin >> m && m != 'M') {

		switch (m) {

			case 'C': carvao++;   break;
			case 'O': ouro++;     break;
			case 'D': diamante++; break;
		}

	}
		int total = carvao + ouro + diamante;

		cout << carvao << endl;
		cout << ouro << endl;
		cout << diamante << endl;
		cout << total << endl;
}
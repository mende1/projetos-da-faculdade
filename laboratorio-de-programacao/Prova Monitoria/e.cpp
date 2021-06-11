#include <iostream> 
#include <string>

using namespace std;

int main () {

	int n, index;
	cin >> n;

	int cod[n];
	string arr[n];

	for (int i=0; i<n; i++) {
		cin >> arr[i] >> cod[i];
	}

	int m;
	cin >> m;

	for (int i=0; i<m; i++) {
		string p;
		cin >> p;

		int l = 0;
		int r = n;

		while (l <= r) {
			int m = l + (r - l) / 2;

			if (arr[m] == p) {
				index = m;
				break;
			}

			else if (arr[m] < p) {
				l = m + 1;
			}

			else {
				r = m - 1;
			}
		}

		if (p == arr[index]) {
			if (cod[index] == 1) {
				cout << "Disponivel" << endl;
			}
			else if (cod[index] == 2) {
				cout << "Emprestado" << endl;
			}
		}
		
		else
			cout << "Nao encontrado" << endl;
	}
}
#include <iostream> 
#include <string>

using namespace std;

int main () {

	int n;
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
		int r = n-1;

		while (l <= r) {
			int m = (l + r) / 2;

			if (p < arr[m]) {
				r = m - 1;
			}

			else if (p > arr[m]) {
				l = m + 1;
			}

			else {
				break;
			}
		}

		if (p == arr[m]) {
			if (cod[m] == 1) {
				cout << "Disponivel" << endl;
			}
			else if (cod[m] == 2) {
				cout << "Emprestado" << endl;
			}
		}
		
		else
			cout << "Nao encontrado" << endl;
	}
}
#include <iostream>

using namespace std;

int main() {
	
	int n, m;
	cin >> n >> m;

	int arr[n];

	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int pont[n] = { 0 };

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int a;
			cin >> a;

			pont[i] += a;
		}
	}

	for (int i=0; i<n-1; i++) {
		int menor_i = i;

		for (int j=i+1; j<n; j++) {
			if (pont[j] > pont[menor_i]) {
				menor_i = j;
			}
		}

		int aux = pont[i];
		pont[i] = pont[menor_i];
		pont[menor_i] = aux;

		aux = arr[i];
		arr[i] = arr[menor_i];
		arr[menor_i] = aux;
	}

	int med = pont[(n/2)];

	for (int i=0; i<n; i++) {
		int var = (pont[i] - med) / 100;
		arr[i] += var;
	}

	for (int i=0; i<n; i++) {
		if (arr[i] < 1200) {
			cout << "Gray\n";
		}
		else if (arr[i] < 1400) {
			cout << "Green\n";
		}
		else if (arr[i] < 1600) {
			cout << "Cyan\n";
		}
		else if (arr[i] < 1900) {
			cout << "Blue\n";
		}
		else if (arr[i] < 2100) {
			cout << "Purple\n";
		}
		else if (arr[i] < 2500) {
			cout << "Yellow\n";
		}
		else if (arr[i] < 3000) {
			cout << "Red\n";
		}
		else {
			cout << "Red Nutella\n";
		}
	}
}
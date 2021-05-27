#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	char arr[n];
	int ans = 0;

	for (int i=0; i<n; i++) {
		cin >> arr[i];

		if (arr[i] == '*') ans++;
	}

	if (ans != 7) {
		cout << "Pedido negado\n";
	}
	else {
		cout << "Pedido realizado\n";

		int aux = 1;
		for (int i=0; i<n; i++) {
			if (arr[i] == '*') {
				cout << aux++ << " ";
			}
			else {
				cout << "$ ";
			}
		}
		cout << "\n";
	}

}
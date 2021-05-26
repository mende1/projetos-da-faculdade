#include <iostream>

using namespace std;

int main() {
	
	int n, m;

	cin >> n >> m;

	int arr[n];

	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int sum = 0;

	for (int i=0; i<m; i++) {
		int aux;
		cin >> aux;

		sum += arr[aux+1];
	}

	if (sum % 3 == 0) {
		cout << "jogador\n";
	}
	else {
		cout << "povoa\n";
	}
}
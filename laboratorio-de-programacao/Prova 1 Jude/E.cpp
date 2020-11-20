#include <iostream>

using namespace std;

int main() {

	int n;

	cin >> n;

	int bag[n];

	for (int i=0; i<n; i++) {
		cin >> bag[i];
	}

	for (int i=n-1; i>=0; i--) {
		cout << bag[i];

		if (i != 0) cout << " ";
	}

	cout << endl;
}
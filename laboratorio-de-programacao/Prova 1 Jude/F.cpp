#include <iostream>

using namespace std;

int main() {

	int n;

	cin >> n;

	int where[n];

	for (int i=0; i<n; i++) {
		cin >> where[i];
	}

	int emerald;
	cin >> emerald;

	for (int i=0; i<n; i++) {
		if (where[i] == emerald) {
			cout << emerald << endl;
			return 0;
		}
	}

	cout << "-1" << endl;
}
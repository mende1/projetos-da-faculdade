#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int arr[n];

	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int p;
	cin >> p;

	for (int i=0; i<n; i++) {
		if (arr[i] == p) {
			cout << p << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// By: mende1

#define endl "\n"
#define int ll

int32_t main() {

	int n;
	cin >> n;

	int arr[n];

	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int h;
	cin >> h;

	int vida = h;

	for (int i=0; i<n; i++) {
		if (arr[i] == 1) {
			vida = h;
		}
		else if (arr[i] != 0) {
			vida -= arr[i];
		}

		if (vida <= 0) {
			cout << "You Died" << endl;
			return 0;
		}
	}

	cout << "Yes, you can" << endl;
}
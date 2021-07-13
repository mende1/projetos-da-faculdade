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

	int id[n], grau[n];

	for (int i=0; i<n; i++) {
		cin >> id[i] >> grau[i];
	}

	for (int j=0; j<n-1; j++) {
		int menor_i = j;
		for (int i=j+1; i<n; i++) {
			if (grau[i] > grau[menor_i]) {
				menor_i = i;
			}
		}

		int aux = grau[j];
		grau[j] = grau[menor_i];
		grau[menor_i] = aux;

		int aux1 = id[j];
		id[j] = id[menor_i];
		id[menor_i] = aux1;
	}

	for (int i=0; i<n; i++) {
		cout << id[i] << " " << grau[i] << endl;
	}
}
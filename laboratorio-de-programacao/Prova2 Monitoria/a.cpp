#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// By: mende1

#define endl "\n"
#define int ll

int32_t main() {

	int n, x, xpmin;

	cin >> n >> x >> xpmin;

	int xp[n], mi[n];

	for (int i=0; i<n; i++) {
		cin >> xp[i] >> mi[i];
	}

	for (int i=0; i<n; i++) {
		if (xp[i] >= xpmin) {
			xp[i] += x;
			mi[i]++;
		}
	}

	for (int i=0; i<n; i++) {
		cout << xp[i] << " " << mi[i] << endl;
	}
}
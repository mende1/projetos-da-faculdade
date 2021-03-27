#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n;
	cin >> n;

	int a[n], sp[n+1];
	
	for (int i=0; i<n; i++) {
		cin >> a[i];
		sp[i+1] = 0;
	}

	for (int i=0; i<n; i++) {
		int sum = a[i];

		for (int j=i+1; j<n; j++) {

			sum += a[j];

			if (sum > n) break;

			sp[sum] = 1;
		}

	}

	int special = 0;

	for (int i=0; i<n; i++) {

		if (sp[a[i]]) special++;
	}

	cout << special << endl;
}

int main(){

	int t; cin >> t;

	while (t--) {
		solve();
	}
}
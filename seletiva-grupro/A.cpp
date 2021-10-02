#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// By: mende1

#define endl "\n"
#define int ll
#define cini(n) int n; cin >> n;
#define fori(x, n) for(int i=x; i<=n; i++)
#define forj(x, n) for(int j=x; j<=n; j++)
#define fork(x, n) for(int k=x; k<=n; k++)

void solve() {
	// -------------------------------------------

	string placa;
	cin >> placa;

	if (placa[4] >= 48 && placa[4] <= 57) {
		cout << "Antigo" << endl;
	}
	else {
		cout << "Novo" << endl;
	}

	// -------------------------------------------
}

int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cini(t);
	// int t=1;

	while(t--) {
		solve();
	}

	return 0;
}

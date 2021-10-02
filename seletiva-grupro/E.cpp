#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// By: mende1

#define endl "\n"
#define int ll
#define cini(n) \
  int n;        \
  cin >> n;
#define fori(x, n) for (int i = x; i <= n; i++)
#define forj(x, n) for (int j = x; j <= n; j++)
#define fork(x, n) for (int k = x; k <= n; k++)

bool is_prime(int n) {
	if (n == 1) return false;

	for (int i=2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

void solve() {
  // -------------------------------------------

	vector<int> arr(1001);

	cini(n);

	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int npar = 0;
	int nimpar = 0;
	int nprimo = 0;

	for (int i=0; i<n; i++) {
		if (arr[i] % 2 == 0) {
			npar++;
		}
		else {
			nimpar++;
		}

		if (is_prime(arr[i])) nprimo++;
	}

	cout << npar << " valor(es) par(es)" << endl;
	cout << nimpar << " valor(es) impar(es)" << endl;
	cout << nprimo << " valor(es) primo(s)" << endl;

  // -------------------------------------------
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//   cini(t);
	int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}

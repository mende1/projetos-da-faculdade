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

#define N 1'000'000'000'000L

unordered_set<int> c;

void precal () {
	for (int i=1; i*i*i<=N; i++) {
		c.insert(i*i*i);
	}
}

void solve() {
	// ----------------------------

	cini(x);

	for (int i=1; i*i*i<=N; i++) {
		if (c.count(x - i*i*i)) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;

	// ----------------------------
}

int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	precal();
	cini(t);
	// ll t=1;

	while(t--) {
		solve();
	}
}

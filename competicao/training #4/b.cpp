#include <bits/stdc++.h>
using namespace std;
// By: mende1

#define endl "\n"
#define int long long
#define cini(n) int n; cin >> n;
#define fori(x, n) for(int i=x; i<n; i++)
#define forj(x, n) for(int j=x; j<n; j++)
#define fork(x, n) for(int k=x; k<n; k++)

bool check (int k, int m) {

	int total = 0;
	int a = k;
	while (a > 0) {
		
		int aux = min(a, m);
		total += aux;
		a -= aux;
		a -= (int)(a / 10);
	}

	return total * 2 >= k;
}

void solve() {
	// ----------------------------

	cini(k);

	int l = 1;
	int r = k;

	int ans = -1;

	while (l <= r) {
		int m = (l + r) / 2;
		if (check(k, m)) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << ans << endl;

	// ----------------------------
}

int32_t main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	// cini(t);
	int t=1;

	while(t--) {
		solve();
	}
}

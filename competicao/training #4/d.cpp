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
 
#define N 30000
 
vector<int> b;
 
void precal () {
 
	b.push_back(0);
	b.push_back(2);
	fori(2, N) {
		int a = b[i-1] + 3*i - 1;
		b.push_back(a);
	}
}
 
void solve() {
	// ----------------------------
 
	cini(n);
 
	int ans = 0;
	while (n > 1) {
 
		int l = -1;
		int r = N;
 
		while (r > l + 1) {
 
			int m = (l + r) / 2;
 
			if (b[m] <= n) {
				l = m;
			}
			else r = m;
 
		}
 
		if (n - b[l] >= 0) {
			ans++; 
		}
		n -= b[l];
	}
 
	cout << ans << endl;
 
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
#include <bits/stdc++.h>
using namespace std;
// By: mende1

#define endl "\n"
#define int long long
#define cini(n) int n; cin >> n;
#define fori(x, n) for(int i=x; i<n; i++)
#define forj(x, n) for(int j=x; j<n; j++)
#define fork(x, n) for(int k=x; k<n; k++)


void solve() {
	// ----------------------------

	cini(n);
	vector<int> a;

	fori (0, n) {
		cini(b);
		a.push_back(b); 
	}

	sort(a.begin(), a.end());

	cini(q);
	while (q--) {

		cini(p);
		if (p < a[0]) {
			cout << 0 << endl;
			continue;
		}
		else if (p >= a[n-1]) {
			cout << n << endl;
			continue;
		}

		int l = 0;
		int r = n-1;
		
		while (l+1 < r) {

			int mid = (l + r) / 2;
			if (a[mid] <= p) {
				l = mid;
			}
			else if (a[mid] > p) {
				r = mid;
			}
			else {
				l = mid;
				break;
			}
		}

		cout << l+1 << endl;

	}

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

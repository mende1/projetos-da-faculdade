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


void solve() {
  // -------------------------------------------

	vector<int> arr1(100000);
	vector<int> arr2(100000);

	cini(n);

	for (int i=0; i<n; i++) {
		cin >> arr1[i];
	}

	for (int i=0; i<n; i++) {
		cin >> arr2[i];
	}

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	if (arr1 == arr2) {
		cout << "Intacta" << endl;
	}
	else {
		cout << "Alterada" << endl;
	}

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

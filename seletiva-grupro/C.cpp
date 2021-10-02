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

	vector<int> arr(300000);

	int n;
	cin >> n;

	for (int i=1; i<=n; i++) {
		cin >> arr[i];
	}

	int32_t ans[2] = { 0 };
	int max = -9223372036854775807;
	int min = 9223372036854775807;

	for (int32_t i=1; i<=n; i++) {
		if (arr[i] > max) {
			max = arr[i];
			ans[0] = i;
		}
		if (arr[i] < min) {
			min = arr[i];
			ans[1] = i;
		}
	}

	if (ans[0] > ans[1]) {
		int32_t aux = ans[0];
		ans[0] = ans[1];
		ans[1] = aux;
	}

	cout << ans[0] << " " << ans[1] << endl;

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

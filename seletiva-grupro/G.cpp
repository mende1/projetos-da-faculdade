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

  int n, k;
  cin >> n >> k;

  int arr[n];

  fori (0, n-1) {
    cin >> arr[i];
  }

  int ans = 0;

  fori (0, n-2) {
    ans += (arr[i+1] - arr[i] - 1) / k;
  }

  cout << ans << endl;

  // -------------------------------------------
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cini(t);
  // int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}

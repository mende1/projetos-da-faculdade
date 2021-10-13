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

  double x1, y1;
  double x2, y2;

  cin >> x1 >> y1;
  cin >> x2 >> y2;

  double dist = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
  double manhathan = abs(x1-x2) + abs(y1-y2);

  cout.precision(4);
  cout << fixed << abs(manhathan) - abs(dist) << endl;

  // -------------------------------------------
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // cini(t);
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}

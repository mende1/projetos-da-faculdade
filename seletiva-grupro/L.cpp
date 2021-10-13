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

  int n;
  cin >> n;

  string str;
  cin >> str;

  bool ok = true;

  for (int i=0; i<n-1; i++) {
    if (str[i] == str[i+1]) {
      ok = false;
      break;
    }
  }

  if (ok) {
    cout << "Bonita" << endl;
  }
  else {
    cout << "Feia" << endl;
  }

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

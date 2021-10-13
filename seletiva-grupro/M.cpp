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

  int di, hi, mi, si;
  cin >> di >> hi >> mi >> si;

  int df, hf, mf, sf;
  cin >> df >> hf >> mf >> sf;

  int s=0, m=0, h=0, d=0;

  if (sf < si) {
    s += (sf+60) - si;
    m -= 1;
  }
  else {
    s += sf - si;
  }

  if (mf < mi) {
    m += (mf+60) - mi;
    h -= 1;
  }
  else {
    m += mf-mi;
  }

  if (hf < hi) {
    h += (hf+24) - hi;
    d -= 1;
  }
  else {
    h += hf - hi;
  }

  d += df - di;

  cout << d << " " << h << " " << m << " " << s << endl;

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

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

  int n, m;
  cin >> n >> m;

  int q;
  cin >> q;

  int ops[q][4];

  int mat[m+2][n+2];

  fori(1, n) {
    forj(1, m) {
      mat[i][j] = 2;
    }
  }

  for (int i = 0; i < q; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> ops[i][j];
    }
  }

  for (int i = 0; i < q; i++) {
    int x1 = ops[i][0];
    int y1 = ops[i][1];
    int x2 = ops[i][2];
    int y2 = ops[i][3];

    for (int x=x1+1; x<=x2+1; x++) {
      for (int y=y1+1; y<=y2+1; y++) {
        mat[x][y]--;
      }
    }

  }

  bool ok = true;

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (mat[i][j] == 0) {
        ok = false;
        break;
      }
    }
  }

  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m - 1; j++) cout << mat[i][j] << " ";
    cout << mat[i][j] << endl;
  }

  if (ok)
    cout << "Bonito" << endl;
  else
    cout << "Feio" << endl;

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

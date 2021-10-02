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

vector<int> pow2;

void precal() {
  for (int i = 0; i <= 60; i++) {
    pow2.push_back(pow(2, i));
  }
}

void solve() {
  // -------------------------------------------

  cini(n);
  vector<int> arr(100000);

  precal();

  // for (int i = 0; i < n; i++) {
  //   cout << pow2[i] << endl;
  // }

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    int key = arr[i];

    int esq = 0;
    int dir = pow2.size() - 1;

    while (esq <= dir) {
      int meio = (esq + dir) / 2;

      if (key < pow2[meio]) {
        dir = meio - 1;
      } else if (key > pow2[meio]) {
        esq = meio + 1;
      } else {
        break;
      }
    }

    int ans = abs(key - pow2[esq]) < abs(key - pow2[dir])
                  ? abs(key - pow2[esq])
                  : abs(key - pow2[dir]);

    // cout << endl;
    // cout << pow2[esq] << endl;
    // cout << pow2[dir] << endl;
    // cout << endl;

    if (i != n-1) cout << ans << " ";
    else cout << ans;
  }

  cout << endl;

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

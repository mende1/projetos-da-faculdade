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

  int min = 5000000000;
  int max = 0;

  int arr[n];

  for (int i=0; i<n; i++) {
    cin >> arr[i];
  }

  for (int i=0; i<n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  int med = (min + max) / 2;
  int med1 = ((min + max) / 2) + 1;

  int ans = 0;
  int ans1 = 0;

  for (int i=0; i<n; i++) {
    ans += abs(arr[i] - med);
    ans1 += abs(arr[i] - med1);
  }

  if (ans1 < ans) {
    ans = ans1;
  }

  cout << ans << endl;

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

#include <iostream>
#include <vector>
#include <algorithm>

#define fori(a, n) for (int i=a; i<n; i++)
#define forj(a, n) for (int j=a; j<n; j++)
#define fork(a, n) for (int k=a; k<n; k++)

using namespace std;

bool comp (int i, int j) { return (i > j); }

int solve(vector<int>& arr, int c) {
  int ans = 0;
  sort(arr.begin(), arr.end(), comp);

  while (!arr.empty()) {
    ans += arr[0] * 2;

    if (arr.size() < c) {
      c = arr.size();
    }

    arr.erase(arr.begin(), arr.begin() + c);
  }

  return ans;
}

int main() {
  int t; cin >> t;
  int n, c, m;

  while (t--) {
    cin >> n >> c >> m;

    vector<int> arr(m);

    fori(0, m) cin >> arr[i];

    cout << solve(arr, c) << endl;
  }
}


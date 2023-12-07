#include <iostream>
#include <vector>
#include <algorithm>

#define fori(a, n) for (int i=a; i<n; i++)
#define forj(a, n) for (int j=a; j<n; j++)
#define fork(a, n) for (int k=a; k<n; k++)

using namespace std;

double solve(vector<int>& arr, int c, int r) {
  double time = 0;

  sort(arr.begin(), arr.end());

  fori(0, c) arr[i] += r;

  fori(0, arr.size()) {
    time += 1.0 / arr[i];
  }

  return time;
}

int main() {
  int t; cin >> t;
  int s, c, r;

  while (t--) {
    cin >> s >> c >> r;

    vector<int> arr(s);

    fori(0, s) cin >> arr[i];

    cout.precision(2);
    cout << fixed << solve(arr, c, r) << endl;
  }

  return 0;
}


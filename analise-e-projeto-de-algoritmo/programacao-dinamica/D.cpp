#include <iostream>
#include <vector>

#define fori(a, n) for (int i=a; i<n; i++)
#define forj(a, n) for (int j=a; j<n; j++)

using namespace std;

bool knapsack(vector<int>& arr, int v) {
	vector<bool> dp(v + 1, false);
    dp[0] = true;

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = v; j >= arr[i]; --j) {
        	dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    return dp[v];
}

int main() {
	int v, n;
	cin >> v >> n;

	vector<int> arr(n);

	fori(0, n) cin >> arr[i];

	if (knapsack(arr, v))
		cout << "S" << endl;
	else
		cout << "N" << endl;

	return 0;
}
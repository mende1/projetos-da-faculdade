#include <iostream>
#include <stack>
#define endl "\n"
#define cini(n) int n; cin >> n;

using namespace std;

bool is_prime (int n) {
	if (n == 1) return false;

	for (int i=2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cini(n);

	int arr[n];
	stack<int> stk;

	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	for (int i=0; i<n; i++) {
		if (not is_prime(arr[i])) {
			stk.push(arr[i]);
		}
		else {
			stk.pop();
			i++;
		}
	}

	int ans = 0;
	int size = stk.size();

	for (int i=1; i<=size; i++) {
		if (not is_prime(i)) {
			ans += stk.top();
		}

		stk.pop();
	}

	cout << ans << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>

#define fori(a, n) for(long long i=a; i<n; i++)

using namespace std;

int main() {
	int cn; cin >> cn;

	while (cn--) {
		long long n; cin >> n;

		vector<long long> arr(n);

		fori (0, n) {
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());

		fori (0, n) {
			cout << arr[i];
			if (i < n-1) {
				cout << " ";
			}
		}

		cout << endl;
	}
}
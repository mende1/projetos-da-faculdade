#include <iostream>

using namespace std;

int main() {

	int op;
	cin >> op;

	switch (op) {
		case 1: {
			int n;
			cin >> n;

			int arr1[n];
			int arr2[n];

			for (int i=0; i<n; i++) {
				cin >> arr1[i];
			}

			for (int i=0; i<n; i++) {
				cin >> arr2[i];
			}

			for (int i=0; i<n; i++) {
				cout << arr1[i] + arr2[i] << " ";
			}
			cout << "\n";
			break;
		};
		case 2: {
			int n;
			cin >> n;

			int arr1[n];
			int arr2[n];

			for (int i=0; i<n; i++) {
				cin >> arr1[i];
			}

			for (int i=0; i<n; i++) {
				cin >> arr2[i];
			}

			int ans = 0;
			for (int i=0; i<n; i++) {
				ans += arr1[i] * arr2[i];
			}
			cout << ans << "\n";
			break;		
		};
		case 3: {
			int n;
			cin >> n;

			int arr1[n];
			int m;

			for (int i=0; i<n; i++) {
				cin >> arr1[i];
			}

			cin >> m;

			for (int i=0; i<n; i++) {
				cout << arr1[i] * m << " ";
			}
			cout << "\n";
			break;
		};
	}
}
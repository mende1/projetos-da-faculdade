#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int n;
	cin >> n;

	string arr[n];

	for (int i=0; i<n; i++) {
		getline(cin, arr[i]);
	}

	int q;
	cin >> q;

	string req[q];

	for (int i=0; i<q; i++) {
		getline(cin, req[i]);
	}

	for (int i=0; i<q; i++) {
		string key = req[i];

		int m;
		int left = 0;
		int right = n-1;

		while (left <= right) {

			m = (left + right) / 2;

			if (key == arr[m]) {
				break;
			}
			else if (key < arr[m]) {
				right = m - 1;
			}
			else {
				left = m + 1;
			}
		}

		cout << arr[m];

		if (key == arr[m]) {
			cout << " foi extinto :(\n";
		}
		else {
			cout << " vive!\n";
		}
	}
}
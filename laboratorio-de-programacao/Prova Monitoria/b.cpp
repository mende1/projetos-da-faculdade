#include <iostream>

using namespace std;

int main () {

	int n;
	cin >> n;

	int arr[n];

	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int x = arr[0], y = arr[0];
	for (int i=0; i<n; i++) {
		if (arr[i+1] == arr[i]+1) {
			y = arr[i+1];
		}

		else {

			cout << x << " " << y << endl;

			x = arr[i+1];
			y = arr[i+1];
		}
	}
}
#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int arr[n];

	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}


	int max = -1;
	for (int i=0; i<n; i++) {
		int min = 1000000;
		for (int j=0; j<n; j++) {
			if (arr[j] < min && arr[j] > max) {
				min = arr[j];
			}
		}

		max = min;
		cout << min << " ";
	}

	cout << "\n";
}
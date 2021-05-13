#include <iostream>

using namespace std;

int main () {

	int n;
	cin >> n;

	int arr[n];

	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	for (int i=0; i<n-1; i++) {
		int menor_i = i;

		for (int j=i+1; j<n; j++) {
			if (arr[j] < arr[menor_i]) {
				menor_i = j;
			}
		}

		int aux = arr[i];
		arr[i] = arr[menor_i];
		arr[menor_i] = aux;
	}

	int ans = 0;

	for (int i=0; i<n-1; i++) {
		if (arr[i+1] != arr[i]+1) {
			ans += arr[i+1] - arr[i] - 1;
		}
	}

	cout << ans << endl;
}
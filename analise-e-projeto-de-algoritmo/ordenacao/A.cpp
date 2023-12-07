#include <iostream>

#define fori(a, n) for(int i=a; i<n; i++)

using namespace std;

int sort(int arr[], int size) {
	int count = 0, i, j, aux;

	while (size--) {

		for (i=0, j=1; i < size; i++, j++) {
			if (arr[i] > arr[j]) {
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
				count++;
			}
		}
	}

	return count;
}

int main() {
	int n;
	cin >> n;

	fori (0, n) {
		int size;
		cin >> size;

		int arr[size];
		fori (0, size) {
			cin >> arr[i];
		}

		cout << "Optimal train swapping takes " + to_string(sort(arr, size)) + " swaps." << endl;
	}
}
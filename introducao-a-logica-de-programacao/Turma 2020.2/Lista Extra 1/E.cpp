#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int A[n];
	int B[n];

	for (int i=0; i<n; i++) {
		cin >> A[i];
	}

	for (int i=0; i<n; i++) {
		cin >> B[i];
	}

	for (int i=0; i<n; i++) {
		if (i % 4 == 0) {
			A[i] *= B[i];
		}
		else if (i % 4 == 1) {
			A[i] -= B[i];
		}
		else if (i % 4 == 2) {
			A[i] /= B[i];
		}
		else if (i % 4 == 3) {
			A[i] = pow(A[i], B[i]);
		}

		while (A[i] > 10) {
			A[i] /= 10;
		}

		if (A[i] < 0) {
			A[i] = -A[i];
		}
	}

	string ans;

	for (int i=0; i<n; i++) {
		string aux;
		stringstream ss;
		ss << A[i];
		ss >> aux;

		ans += aux;
	}

	if (ans.size() < 6) {
		int c = 6 - ans.size();
		for (int i=0; i<c; i++) {
			ans += '0';
		}
	}
	int pivot = ans.size() - 6;

	for (int i=pivot; i<ans.size(); i++) {
		if (ans.at(i)) {
			cout << ans.at(i);
		}
		else {
			cout << 0;
		}
	}

	cout << "\n";
}
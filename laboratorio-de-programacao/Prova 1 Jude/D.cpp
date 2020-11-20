#include <iostream>

using namespace std;

int main() {

	int n;

	cin >> n;

	char dragon[n];

	int shenlong = 0;

	for (int i=0; i<n; i++) {
		cin >> dragon[i];

		if (dragon[i] == '*') shenlong++;
	}

	if (shenlong != 7) {
		cout << "Pedido negado" << endl;

		return 0;
	}

	else {
		cout << "Pedido realizado" << endl;

		int count = 1;

		for (int i=0; i<n; i++) {
			if (dragon[i] == '*') {
				cout << count;
				count++;
			} else {
				cout << "$";
			}

			if (i != n-1) cout << " ";
			
		} cout << endl;
	}
}
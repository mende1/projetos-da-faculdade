#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, a;
	cin >> n;

	vector<int> vet;

	int joias = 0;

	for (int i=0; i<n; i++) {
		cin >> a;

		if (a == 0 or a == 7 or a == 11 or a == 14 or a == 17 or a == 19) {
			joias++;
			vet.push_back(a);
		}
	}

	if (joias == 6) {
		cout << "Vingadores Avante\n";
	}
	else if (joias > 0 and joias < 6) {
		for (int i=0; i<vet.size(); i++) {
			cout << vet.at(i) << " ";
		} puts("");

		cout << "Vingadores Atencao\n";
	}
	else {
		cout << "Pizza\n";
	}
}
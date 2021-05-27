#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	int n;
	cin >> n;
	cin.ignore();

	for (int i=0; i<n; i++) {
		string name;
		getline(cin, name);

		cout << (char)((int)name[0] - 32) << ". ";

		int spaces = count(name.begin(), name.end(), ' ');

		int k = 0;
		for (int j=0; j<spaces-1; j++) {
			while (name[++k] != ' ');
			cout << (char)((int)name[++k] - 32) << ". ";
		}

		while (name[++k] != ' ');
		cout << (char)((int)name[++k] - 32);

		while (name[++k]) {
			cout << name[k];
		}

		cout << endl;
	}
}
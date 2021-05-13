#include <iostream>

using namespace std;

int main () {

	int x;
	cin >> x;

	char arr[7][7];

	for (int i=0; i<7; i++) {
		for (int j=0; j<7; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;

	int i=0; int j=0;
	while (arr[i][j] != '*') {
		
		if (arr[i][j] == 'v') {
			i++;
			ans++;
			while (arr[i][j] == '.') {
				i++;
				ans++;
			}
		}

		else if (arr[i][j] == '>') {
			j++;
			ans++;
			while (arr[i][j] == '.') {
				j++;
				ans++;
			}
		}

		else if (arr[i][j] == '<') {
			j--;
			ans++;
			while (arr[i][j] == '.') {
				j--;
				ans++;
			}
		}

		else if (arr[i][j] == '^') {
			i--;
			ans++;
			while (arr[i][j] == '.') {
				i--;
				ans++;
			}
		}
	}

	if (ans <= x) 
		cout << "consegue" << endl;
	else
		cout << "nao consegue" << endl;
}
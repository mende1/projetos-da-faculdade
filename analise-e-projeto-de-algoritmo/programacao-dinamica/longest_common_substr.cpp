#include <iostream>
#include <string>
#include <vector>
#define fori(a, n) for (int i=a; i<n; i++)
#define forj(a, n) for (int j=a; j<n; j++)

using namespace std;

string longest_common_string(string str1, string str2) {
	int rows = str1.size() + 1;
	int cols = str2.size() + 1;
	vector<vector<int>> mat(rows, vector<int>(cols));

	int max_length = 0;
	int ending_index = str1.size();

	fori(0, rows) {
		forj(0, cols) {
			if (str1[i-1] == str2[j-1]) {
				mat[i][j] = mat[i-1][j-1] + 1;
				if (mat[i][j] > max_length) {
					max_length = mat[i][j];
					ending_index = i;
				} 
			}
		}
	}

	fori(0, rows) {
		forj(0, cols) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	return str1.substr(ending_index - max_length, ending_index);
}

int main() {
	string str1 = "ababbababbaba";
	string str2 = "baabbababaaba";

	cout << longest_common_string(str1, str2) << endl;

	return 0;
}
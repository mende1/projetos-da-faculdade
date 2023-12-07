#include <iostream>
#include <vector>
#include <algorithm>

#define fori(a, n) for (int i=a; i<n; i++)
#define forj(a, n) for (int j=a; j<n; j++)

using namespace std;

int knapsack(vector<int> w, vector<int> v, int p) {
	int rows = w.size() + 1;
	int cols = p + 1;
	vector<vector<int>> mat(rows, vector<int>(cols));

	fori(1, rows) {
		forj(1, cols) {
			if (w[i-1] <= j) {
				mat[i][j] = max(mat[i-1][j], mat[i-1][j-w[i-1]] + v[i-1]);
			} else {
				mat[i][j] = mat[i-1][j];
			}
		}
	}

	fori(0, cols) cout << i << "\t";
	cout << endl;

	fori(0, rows) {
		forj(0, cols) {
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}

	return mat[rows-1][cols-1];
}

int main() {
	// 				  0  1  2  3
	vector<int> w = { 3, 2, 4, 1 };
	vector<int> v = { 8, 3, 9, 6 };

	int p = 5;

	cout << knapsack(w, v, p) << endl;
}
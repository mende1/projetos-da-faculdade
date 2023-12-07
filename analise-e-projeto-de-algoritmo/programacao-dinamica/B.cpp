#include <iostream>
#include <string>
#include <vector>

#define fori(a, n) for (int i=a; i<n; i++)
#define forj(a, n) for (int j=a; j<n; j++)

using namespace std;

int dinamic_programming(vector<int> w, vector<int> v, int p) {
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

	return mat[rows-1][cols-1];
}

int main() {
	int n, p;

	while (cin >> n >> p && n != 0) {
		vector<int> w(n);
		vector<int> v(n);

		fori(0, n) {
			cin >> v[i] >> w[i];
		}

		cout << dinamic_programming(w, v, p) << " min." << endl;
	}

	return 0;
}
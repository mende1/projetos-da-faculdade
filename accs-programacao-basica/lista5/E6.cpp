#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int mat[n][n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }

    int harry = 0, rony = 0;

    int x, y;
    cin >> x >> y;

    for (int i=0; i<n; i++) {
        harry += mat[x][i];
        rony  += mat[i][y];
    }

    if (x == y) {
        harry -= mat[x][y];
    }
    else if (y > x) {
        harry -= mat[x][y];
    }
    else {
        rony -= mat[x][y];
    }

    cout << "Harry " << harry << endl;
    cout << "Ron "    << rony  << endl;
}

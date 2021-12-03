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

    int ans = 0;

    int c;
    cin >> c;

    for (int i=0; i<c; i++) {
        int x, y;
        cin >> x >> y;

        ans += mat[x][y];
    }

    cout << ans << endl;
}

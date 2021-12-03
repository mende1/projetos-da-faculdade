#include <iostream>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    bool mat[n][n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int a;
            cin >> a;

            mat[i][j] = bool(a);
        }
    }

    int ans = 0;

    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;

        for (int j=x; j>=0; j--) {
            if (mat[j][y]) {
                ans++;
                mat[j][y] = false;
                break;
            }
        }
    }

    cout << ans << endl;
}

#include <iostream>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int mat[n][m];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mat[i][j];
        }
    }

    int ans = 0;

    for (int i=0; i<n; i++) {
        if (i % 2 == 0) {
            for (int j=0; j<m; j++) {
                ans += mat[i][j];
                if (ans < 0) {
                    ans = 0;
                }
            }
        }
        else {
            for (int j=m-1; j>=0; j--) {
                ans += mat[i][j];
                if (ans < 0) {
                    ans = 0;
                }
            }
        }
    }

    cout << ans << endl;
}

#include <iostream>

using namespace std;

int main() {

    int mat[7][7];

    for (int i=0; i<7; i++) {
        for (int j=0; j<7; j++) {
            cin >> mat[i][j];
        }
    }

    int ans = 0;

    for (int i=0; i<7; i++) {
        for (int j=0; j<=i; j++) {
            if (mat[i][j]) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

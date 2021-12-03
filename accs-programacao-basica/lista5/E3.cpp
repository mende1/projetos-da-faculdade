#include <iostream>

using namespace std;

int main() {

    int l, c;
    cin >> l >> c;

    int a[l][c];
    int b[l][c];
 
    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            cin >> a[i][j];
        }
    }

    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            cin >> b[i][j];
        }
    }

    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            cout << a[i][j] - b[i][j] << " ";
        }
        cout << endl;
    }
}

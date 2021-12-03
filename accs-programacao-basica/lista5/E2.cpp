#include <iostream>

using namespace std;

int main() {

    int l, c;
    cin >> l >> c;

    int mat[l][c];

    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i=0; i<l; i++) {
        for (int j=0; j<c-1; j++) {
            if (mat[i][j] == 0 and mat[i][j+1] == 0) {
                cout << "Fileira: " << i + 1 << endl;
                cout << "Assentos: " << j + 1 << " e " << j + 2 << endl;
                return 0;
            }
        }
    }
}

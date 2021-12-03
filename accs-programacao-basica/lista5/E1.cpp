#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int mat[10][10];

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (mat[i][j] == n) {
                cout << "sim" << endl;
                return 0;
            }
        }
    }

    cout << "nao" << endl;
}

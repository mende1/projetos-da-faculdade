#include <iostream>

using namespace std;

int main() {

    int n = 10;
    char mat[n][n];
    char aux[n+2][n+2];

    for (int i=0; i<n+2; i++) {
        for (int j=0; j<n+2; j++) {
            aux[i][j] = '0';
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            aux[i][j] = mat[i-1][j-1];
        }
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            bool agua = false;
            if (aux[i][j] == 't') {
                if (aux[i][j+1] == '*') {
                    agua = true;
                }
                else if (aux[i][j-1] == '*') {
                    agua = true;
                }
                else if (aux[i+1][j] == '*') {
                    agua = true;
                }
                else if (aux[i-1][j] == '*') {
                    agua = true;
                }
            }

            if (agua) {
                aux[i][j] = 'p';
            }
        }
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            cout << aux[i][j] << " ";
        }
        cout << endl;
    }
}

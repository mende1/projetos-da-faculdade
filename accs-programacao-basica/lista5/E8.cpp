#include <iostream>

using namespace std;

int main() {

    int mat[8][8];

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cin >> mat[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    int ans = 0;

    // para cima

    for (int i=x; i>=0; i--) {
        if (mat[i][y] == 1 and i != x) {
            break;
        }
        else if (mat[i][y] == 2) {
            ans++;
            break;
        }
    }

    // para baixo

    for (int i=x; i<8; i++) {
        if (mat[i][y] == 1 and i != x) {
            break;
        }
        else if (mat[i][y] == 2) {
            ans++;
            break;
        }
    }

    // para esquerda

    for (int i=y; i>=0; i--) {
        if (mat[x][i] == 1 and i != y) {
            break;
        }
        else if (mat[x][i] == 2) {
            ans++;
            break;
        }
    }

    // para direita

    for (int i=y; i<8; i++) {
        if (mat[x][i] == 1 and i != y) {
            break;
        }
        else if (mat[x][i] == 2) {
            ans++;
            break;
        }
    }

    cout << ans << endl;
}

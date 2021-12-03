#include <iostream>
#define int long long

using namespace std;

int32_t main() {

    int c, o, l, x;
    cin >> c >> o >> l >> x;

    int C = c / 4;
    int O = o / 8;
    int L = l / 2;
    int X = x / 1;

    int min = C;

    if (O < min) {
        min = O;
    }
    if (L < min) {
        min = L;
    }
    if (X < min ) {
        min = X;
    }

    int a = min * 1259;

    int r = a / 60;
    int seg = a % 60;

    int hora = r / 60;
    int minu = r % 60;

    cout << hora << " h " << minu << " m " << seg << " s" << endl;
}
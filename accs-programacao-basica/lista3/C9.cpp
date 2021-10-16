#include <iostream>

using namespace std;

int main() {

    int x, y;

    cin >> x >> y;

    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            cout << "X";
        }
        cout << endl;
    }
}
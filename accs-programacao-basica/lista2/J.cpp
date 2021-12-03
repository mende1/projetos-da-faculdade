#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    if ((x4 < x1) || (x3 > x2)) {
        cout << "Não existe interseção entre os quadros";
    } else if ((y4 < y1) || (y3 > y2)) {
        cout << "Não existe interseção entre os quadros";
    } else {
        cout << "Existe interseção entre os quadros";
    }

}
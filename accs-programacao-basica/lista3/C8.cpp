#include <iostream>

using namespace std;

int main() {

    float n;
    cin >> n;

    while (n > 1) {
        n /= 2;
    }

    if (n == 1) {
        cout << "Dattebayo" << endl;
    }
    else {
        cout << "Tururuuu" << endl;
    }
}
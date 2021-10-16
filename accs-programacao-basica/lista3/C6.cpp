#include <iostream>

using namespace std;

int main() {

    char ch;
    cin >> ch;

    while (ch != '#') {
        int s;
        cin >> s;

        if (s < 90) {
            cout << ch << " Internação" << endl;
        }
        else {
            cout << ch << " Alta" << endl;
        }

        cin >> ch;
    }
}
#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;

    int p;
    
    while (cin >> p && p != 0) {
        if (p > t) {
            cout << "ALARME" << endl;
            return 0;
        }
    }

    cout << "O Havai pode dormir tranquilo" << endl;
}
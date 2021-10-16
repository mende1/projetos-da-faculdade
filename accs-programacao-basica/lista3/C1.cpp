#include <iostream>

using namespace std;

int main() {

    string str;
    getline(cin, str);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cout << str << endl;
    }
}
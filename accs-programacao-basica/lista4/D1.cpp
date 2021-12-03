#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int c;
    cin >> c;

    for (int i=0; i<n; i++) {
        if (c == arr[i]) {
            cout << c << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
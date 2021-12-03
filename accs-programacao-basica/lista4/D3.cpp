#include <iostream>

#define fori(a, n) for(int i=a; i<n; i++)

using namespace std;

int main() {
    
    int n;
    cin >> n;

    int u[n], v[n], uv[n];

    fori (0, n) {
        cin >> u[i];
    }
    fori (0, n) {
        cin >> v[i];
    }
    fori (0, n) {
        cin >> uv[i];
    }

    fori (0, n) {
        if (u[i] + v[i] != uv[i]) {
            cout << "NOPE :(" << endl;
            return 0;
        }
    }

    cout << "OK" << endl;
}
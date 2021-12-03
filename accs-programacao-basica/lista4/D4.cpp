#include <iostream>

#define fori(a, n) for(int i=a; i<n; i++)

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;

    int arr[m] = { 0 };

    fori(0, n) {
        int k;
        cin >> k;

        for (int j=0; j<m; j += k) {
            arr[j] = 1;
        }
    }

    fori (0, m) {
        cout << arr[i] << " ";
    }

    cout << endl;
}
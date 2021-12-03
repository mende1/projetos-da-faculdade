#include <iostream>

#define fori(a, n) for(int i=a; i<n; i++)

using namespace std;

int main() {
    
    int n;
    cin >> n;

    int arr[n];

    fori (0, n) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    fori (0, n) {
        cout << arr[i] * k << " ";
    }

    cout << endl;
}
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

    for (int i=n-1; i>=0; i--) {
        cout << arr[i] << " ";
    }

    cout << endl;
}
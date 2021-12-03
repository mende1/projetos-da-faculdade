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

    int ans = 0;

    for (int i : arr) {
        ans += i;
    }

    int aux = 0;
    fori (0, n) {
        aux += arr[i];
        if (aux == ans / 2) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
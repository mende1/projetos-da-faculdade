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

    int c;
    cin >> c;

    int ans = 0;

    for (int elem : arr) {
        if (ans + elem <= c) {
            ans += elem;
        }
        else {
            break;
        }
    }

    cout << ans / 100 << endl;
}
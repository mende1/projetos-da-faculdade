#include <iostream>

#define fori(a, n) for(int i=a; i<n; i++)

using namespace std;

int main() {
    
    int n;
    cin >> n;

    int arr[n];
    int ans[1000005] = { 0 };

    fori (0, n) {
        cin >> arr[i];
    }

    for (int elem : arr) {
        ans[elem] = 1;
    }

    for (int i=0; i<1000000; i++) {
        if (ans[i]) {
            cout << i << " "; 
        }
    }

    cout << endl;
}
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

    int x;
    cin >> x;

    int vida = x;

    for (int elem : arr) {
        if (elem == 0) {
            continue;
        }
        else if (elem == 1) {
            x = vida;
        }
        else {
            x -= elem;
            if (x <= 0) {
                cout << "You Died\n";
                return 0;
            }
        }
    }

    cout << "Yes, you can\n";
}
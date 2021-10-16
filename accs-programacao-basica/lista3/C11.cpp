#include <iostream>

using namespace std;

int main() {

    int e, p;
    cin >> e >> p;
    int ans = 0;

    while (e > 0 && p > 0) {
        e -= p;
        p -= 1;
        ans++;
    }

    if (e > 0) {
       cout << "F" << endl;  
    }
    else {
        cout << ans << endl;
    }
}
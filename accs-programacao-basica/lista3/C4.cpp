#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    int ans = 0;

    for (int i=0; i<n; i++) {
        int l, m, t;
        cin >> l >> m >> t;

        ans += (l * m) + t;
    }

    cout << ans << endl;
}
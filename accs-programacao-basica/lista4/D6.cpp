#include <iostream>

#define fori(a, n) for(int i=a; i<n; i++)

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;

    int a = m;

    int arr[n];
    int ans[10002];

    fori (0, 10002) {
        ans[i] = -1;
    }

    fori (0, n) {
        cin >> arr[i];
    }

    int aux = 0;

    for (int i=n-1; i>=n-m; i--) {
        if (arr[i] == 0) {
            m++;
        }
        else {
            ans[aux++] = arr[i];
        }
    }

    for (int i=a-1; i>=0; i--) {
        cout << ans[i] << " ";
    }

    cout << endl;
}
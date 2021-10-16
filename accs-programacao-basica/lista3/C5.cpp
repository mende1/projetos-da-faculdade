#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    float ans = 0;
    int p;

    for (int i=0; i<n; i++) {
        cin >> p;
        
        ans += p * 0.05;
    }

    if (ans > p) {
        cout << "Escolheu o seu destino!" << endl;
    }
    else {
        cout << "Fez de mim o que eu sou!" << endl;
    }
}
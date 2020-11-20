#include <iostream>
 
using namespace std;
 
int main() {

    int n; cin >> n;

    int soma = 0;

    for (int i = 1; i < n; i++) {
        double aux;
        int div;

        div = n/i;
        aux = (double)n/i;
        
        if (div == aux) {
            soma += i;
        }
    }

    if (soma == n) cout << n << " eh perfeito" << endl;
    else cout << n << " nao eh perfeito" << endl;
}
#include <iostream>
 
using namespace std;
 
int main() {

    int pa, pb;
    double ga, gb;

    cin >> pa >> pb >> ga >> gb;

    int anos = 0;

    while (pa <= pb && anos <= 100) {

        pa = pa + (ga*pa)/100;
        pb = pb + (gb*pb)/100;

        anos++;
    }

    if (anos > 100) cout << "Mais de 1 seculo." << endl;
    else cout << anos << " anos." << endl;

}
#include <iostream>
#include <string>

using namespace std;

int main() {

    string Fibo1;
    string Fibo2;

    string resultado;

    getline(cin, Fibo1);
    getline(cin, Fibo2);

    int tam1 = Fibo1.size();
    int tam2 = Fibo2.size();

    if (tam2 > tam1) {
        Fibo1.insert(Fibo1.begin(), '0');
    }

    int carry = 0;

    for (int i=tam2-1; i>=0; i--) {

        int num1 = (int)(Fibo1.at(i)) - 48;
        int num2 = (int)(Fibo2.at(i)) - 48;

        int soma = num1 + num2 + carry;

        if (soma > 9) {

            carry = soma / 10;
            soma -= carry*10;

        } else {

            carry = 0;
        }

        char aux = (char)(soma + 48);

        if (i == tam2-1) {
            
            resultado.push_back(aux);
        } else {

            resultado.insert(resultado.begin(), aux);
        }
    }

    cout << resultado << endl;
}
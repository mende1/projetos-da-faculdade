#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <algorithm>

using namespace std;

#define MAX 100
#define TESTES 100

bool buscaSeq(vector<int> v, int k, int * cont) {

    for (int i=0; i<v.size(); i++) {
        *cont += 1;
        if (k == v[i]) {
            return true;
        }
    }

    return false;
}

bool buscaBin (vector<int> v, int k, int * cont) {

    sort(v.begin(), v.end());

    int esq = 0, dir = v.size() - 1;

    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        *cont += 1;

        if (v[meio] == k) {
            return true;
        }
        else if (v[meio] > k) {
            dir = meio - 1;
        }
        else {
            esq = meio + 1;
        }
    }

    return false;
}

void print_vet(vector<int> vet) {

	cout << "\nTamanho do Vetor (n) = " << vet.size() << endl;
    cout << "Conteúdo de vet: [";

    int cont = 0;

    for (vector<int>::iterator it = vet.begin(); it != vet.end(); ++it) {
        if (it != (vet.end() - 1)) cout << *it << ", ";
        else { cout << "]" << endl; break; }
        cont++;
    }
}

int main() {

    vector<int> v;

	cout << "tamanho do vetor = " << v.size() << endl;

    srand ( time(NULL) );

    for (unsigned int i=0; i < MAX; i++) {
        v.push_back(rand() % MAX);
    }

    print_vet(v);

    for (unsigned int i=0; i < TESTES; i++) {
        int k = rand() % MAX;

        // Busca Sequencial

        int cont = 0, *p_cont = &cont;
        bool achou = buscaSeq(v, k, p_cont);
        string res = (achou) ? "SIM" :  "NAO";
        cout << "Busc. Seq. ->\t Chave: " << k << ";\tAchou? " << res << ";\tQntd Ops: " << cont << endl;

        // Busca Binária

        int cont2 = 0, *p_cont2 = &cont2;
        achou = buscaBin(v, k, p_cont2);
        res = (achou) ? "SIM" :  "NAO";
        cout << "Busc. Bin. ->\t Chave: " << k << ";\tAchou? " << res << ";\tQntd Ops: " << cont2 << endl << endl;

    }
    	
 	return 0;        
}
#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <algorithm>

using namespace std;

#define MAX 20

bool buscaSeq(vector<int> v, int k) {

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
        v.push_back(rand() % MAX*10);
    }

    print_vet(v);
    	
 	return 0;        
}
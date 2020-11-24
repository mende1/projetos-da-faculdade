#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <unistd.h>

const int MAX[5] = {20, 200, 2000, 20000};

using namespace std;

/**************************************
*** struct para guardar informações do máximo, mínimo e o f(n) de cada algoritmo que seja usado
**************************************/
struct values {
    int max;
    int min;
    int count;
};

/**************************************
*** declaração de escopo global do array de 3 dimensões
*** para armazenar os dados necessários de cada caso
*** para fazer a análise empirica do algoritmo
** x identifica os casos de teste, que tem 4 (20, 200, 2000, 20000)
** y identifica cada caso, tendo 3 deles (randomico, sort decresc. e cresc.)
** z identifica cada algoritmo, tendo 3 deles (1, 2 e 3)
**************************************/
int data[4][3][3];

/**************************************
*** algoritmo versão 1.0, composto apenas de dois 'ifs'
*** melhor caso esperado: 2(n-1)
***   pior caso esperado: 2(n-1)
***  médio caso esperado: 2(n-1)
**************************************/
values minMaxVetor1 (vector<int> vet, int cases, int lim) {

    values v;

    v.max = vet[0];
    v.min = vet[0];
    v.count = 0;

    for (unsigned int i = 1; i < vet.size(); i++) {
        
        if (v.max < vet[i]) v.max = vet[i]; v.count++;
        if (v.min > vet[i]) v.min = vet[i]; v.count++;
    }

    // armazenamento dos dados para análise
    data[lim][cases][0] = v.count;
    return v;
}

/**************************************
*** algoritmo versão 2.0, composto de 'ifs' e 'elses'
*** melhor caso esperado: n-1
***   pior caso esperado: 2(n-1)
***  médio caso esperado: 3n/2 - 3/2
**************************************/
values minMaxVetor2 (vector<int> vet, int cases, int lim) {

    values v;

    v.max = vet[0];
    v.min = vet[0];
    v.count = 0;

    for (unsigned int i = 1; i < vet.size(); i++) {
        
        v.count++;
        if (v.max <= vet[i]) v.max = vet[i];
        else {  
            if (v.min > vet[i]) v.min = vet[i];
            v.count++;
        }
    
    }

    // armazenamento dos dados para análise
    data[lim][cases][1] = v.count;
    return v;
}

/**************************************
*** algoritmo versão 3.0, capaz de fazer cada verificação através de pares
*** melhor caso esperado: 3n/2 - 2
***   pior caso esperado: 3n/2 - 2
***  médio caso esperado: 3n/2 - 2
**************************************/
values minMaxVetor3 (vector<int> vet, int cases, int lim) {

    values v;

    v.max = vet[0];
    v.min = vet[0];
    v.count = 0;

    int tam = vet.size();

    int i, finalDoAnel;

    v.count++;
    if ((tam & 1) > 0) {
        vet.push_back(vet[tam-1]);
        finalDoAnel = tam;
    } else {
        finalDoAnel = tam-1;
    }

    v.count++;
    if (vet[0] > vet[1]) {
        v.max = vet[0];
        v.min = vet[1];
    } else {
        v.max = vet[1];
        v.min = vet[0];
    }

    i = 3;

    while (i <= finalDoAnel) {

        if (vet[i-1] > vet[i]) {
            if (vet[i-1] > v.max) v.max = vet[i-1];
            if (vet[i] < v.min) v.min = vet[i];
        } else {
            if (vet[i-1] < v.min) v.min = vet[i-1];
            if (vet[i] > v.max) v.max = vet[i];
        } v.count += 3;

        i += 2;
    }

    // armazenamento dos dados para análise
    data[lim][cases][2] = v.count;
    return v;
}

/**************************************
*** função para ordenar os vetores tanto em ordem cresc. ou descres.
**************************************/
vector<int> sort (vector<int> vet, string sort) {
    int i, j, aux;
    int tam = vet.size();

    if (sort == "ascending") {
        for (i=0; i<tam-1; i++) {
            for (j=i+1; j<tam; j++) {
                if (vet[j] < vet[i]) {
                    aux = vet[j];
                    vet[j] = vet[i];
                    vet[i] = aux;
                }
            }
        }
    } else if (sort == "descending") {
       for (i=0; i<tam-1; i++) {
            for (j=i+1; j<tam; j++) {
                if (vet[j] > vet[i]) {
                    aux = vet[j];
                    vet[j] = vet[i];
                    vet[i] = aux;
                }
            }
        } 
    }

    return vet;
}

void line() {
    cout << "\n========================";
    cout << "===========================";
    cout << "===================" << endl;
}

/**************************************
*** função para printar na tela os dados do vetor e seu conteúdo
**************************************/
void print_vet(vector<int> vet, string id, int lim = 0) {

    if (lim != 0) { 
        line();
        cout << "---> N = " << lim << " <---";
    }
    line();

    if (id == "random")
        cout << " -> VETOR RÂNDOMICO <-" << endl;
    else if (id == "sort_descending")
        cout << " -> VETOR ORDENADO DECRESCENTE <-" << endl;
    else if (id == "sort_ascending")
        cout << " -> VETOR ORDENADO CRESCENTE <-" << endl;

	cout << "\nTamanho do Vetor (n) = " << vet.size() << endl;
    cout << "Conteúdo de vet: [";

    int cont = 0;

    for (vector<int>::iterator it = vet.begin(); it != vet.end(); ++it) {
        if (it != (vet.end() - 1)) cout << *it << ", ";
        if (cont == 11) { cout << "...]" << endl; break; }
        cont++;
    }
}

/**************************************
*** função para printar os maiores, menores e f(n) de cada algoritmo diferente
**************************************/
void print_message(values v[3]) {

    cout << "\n [Comprovado que para os três algoritmos, tais valores são os mesmos!]" << endl;
    cout << "---> Maior: " << v[0].max << endl;
    cout << "---> Menor: " << v[0].min << endl << endl;

    for (unsigned int i=0; i<3; i++) {
        cout << "\n-- ALGORITMO VERSÃO 0" << i+1 << " --" << endl;
        cout << "f(n) = " << v[i].count << endl;
    }

}

/**************************************
*** função de análise de cada caso e algoritmo e
*** recebe os dados de todo o resto do programa
**************************************/
void print_conclusion() {
    cout << "==== ANÁLISE ====";
    line();

    int x=0;

    while (x < 4) {
        cout << "---> N = " << MAX[x] << endl;

        for (int y=0; y<3; y++) {
            switch (y) {
                case 0: cout << "  * CASO RANDÔMICO" << endl; break; 
                case 1: cout << "  * CASO ORDENADO CRESCENTE" << endl; break; 
                case 2: cout << "  * CASO ORDENADO DESCRESCENTE" << endl; break; 
            }

            for (int z=0; z<3; z++) {
                cout << "    > " << z+1 << "º algoritmo" << endl;
                cout << "      - f(n) = " << data[x][y][z] << endl << endl;
                if (z == 2 && y != 2) cout << endl;
            }
        }

        x++;
    }

    line();
    cout << "Conclusão: \n";
    cout << "Percebemos que em todos os casos de teste, o primeiro algoritmo sempre consegue " << endl;
    cout << "os mesmos valores de f(x) independente da organização do vetor, sempre 2(n-1)" << endl << endl;
    cout << "Também o 3º algoritmo sempre consegue (3n/2) - 2 em todas as organizações do vetor" << endl;
    cout << "e percebemos também que é o mais otimizado na maioria dos casos devido ao seu pior" << endl << endl;
    cout << "Já o 2º algoritmo é uma carroça quando o vetor está em ordem decrescente, sendo o seu" << endl;
    cout << "pior caso 2(n-1), porém é o mais otimizado quando este mesmo vetor se encontra ordenado" << endl;
    cout << "em ordem crescente, assim o mesmo consegue n-1 operações, sendo seu melhor caso." << endl << endl;

}

/**************************************
*** função princiapal
**************************************/
int main() {

    int lim = 0;

    while (lim < 4) {
    
        srand ( time(NULL) );

        /*************************************************
        ***** VETOR VERSÃO RANDÔMICA
        *************************************************/
        vector<int> vet;
        values v[3];

        for (unsigned int i=0; i < MAX[lim]; i++) {
            vet.push_back(rand() % 100);
        }

        print_vet(vet, "random", MAX[lim]);

        v[0] = minMaxVetor1(vet, 0, lim);
        v[1] = minMaxVetor2(vet, 0, lim);
        v[2] = minMaxVetor3(vet, 0, lim);

        print_message(v);

        /*************************************************
        ***** VETOR VERSÃO ORDNENADA CRESCENTE
        *************************************************/
        vector<int> vet_sort_ascending;
        values v_sort_ascending[3];

        vet_sort_ascending = sort(vet, "ascending");

        print_vet(vet_sort_ascending, "sort_ascending");

        v_sort_ascending[0] = minMaxVetor1(vet_sort_ascending, 1, lim);
        v_sort_ascending[1] = minMaxVetor2(vet_sort_ascending, 1, lim);
        v_sort_ascending[2] = minMaxVetor3(vet_sort_ascending, 1, lim);

        print_message(v_sort_ascending);

        /*************************************************
        ***** VETOR VERSÃO ORDENADA DECRESCENTE
        *************************************************/
        vector<int> vet_sort_descending;
        values v_sort_descending[3];

        vet_sort_descending = sort(vet, "descending");

        print_vet(vet_sort_descending, "sort_descending");

        v_sort_descending[0] = minMaxVetor1(vet_sort_descending, 2, lim);
        v_sort_descending[1] = minMaxVetor2(vet_sort_descending, 2, lim);
        v_sort_descending[2] = minMaxVetor3(vet_sort_descending, 2, lim);

        print_message(v_sort_descending);

        lim++;
    }

    line();
    print_conclusion();
    line();

 	return 0;
}
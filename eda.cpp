#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <sys/time.h>

#define MAX 20000

using namespace std;

// ********************************************************************
// ** Funcao que determina o maior e o menor elemento de um vetor 
// ** com N elementos. 
// ** Primeira versão.
// ********************************************************************
int minMaxVetor1(vector<int> v) {

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    int max = v[0];
    int min = v[0];

    for (unsigned int i = 1; i < v.size(); i++) {
        
        if (max < v[i]) max = v[i];
        if (min > v[i]) min = v[i];
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    cout << "====> (v.1) O maior elemento do conjunto é: " << max << endl;
    cout << "====> (v.1) O menor elemento do conjunto é: " << min << endl;
    cout << "====> (v.1) Tempo de execução: " << delta_us << "ms" << endl << endl;

    return 0;
}

// ********************************************************************
// ** Funcao que determina o maior e o menor elemento de um vetor 
// ** com N elementos. 
// ** Segunda versão.
// ********************************************************************
int minMaxVetor2(vector<int> v) {

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    int max = v[0];
    int min = v[0];

    for (unsigned int i = 1; i < v.size(); i++) {
        
        if (max < v[i]) max = v[i];
        else if (min > v[i]) min = v[i];
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    cout << "====> (v.2) O maior elemento do conjunto é: " << max << endl;
    cout << "====> (v.2) O menor elemento do conjunto é: " << min << endl;
    cout << "====> (v.2) Tempo de execução: " << delta_us << "ms" << endl << endl;

    return 0;
}

// ********************************************************************
// ** Funcao que determina o maior e o menor elemento de um vetor 
// ** com N elementos. 
// ** Terceira versão.
// ********************************************************************
int minMaxVetor3(vector<int> v) {

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    int max = v[0];
    int min = v[0];
    int tam = v.size();

    int i, finalDoAnel;

    if ((tam & 1) > 0) {
        v.push_back(v[tam-1]);
        finalDoAnel = tam;
    } else {
        finalDoAnel = tam-1;
    }

    if (v[0] > v[1]) {
        max = v[0];
        min = v[1];
    } else {
        max = v[1];
        min = v[0];
    }

    i = 3;

    while (i <= finalDoAnel) {

        if (v[i-1] > v[i]) {
            if (v[i-1] > max) max = v[i-1];
            if (v[i] < min) min = v[i];
        } else {
            if (v[i-1] < min) min = v[i-1];
            if (v[i] > max) max = v[i];
        }

        i += 2;
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    cout << "====> (v.3) O maior elemento do conjunto é: " << max << endl;
    cout << "====> (v.3) O menor elemento do conjunto é: " << min << endl;
    cout << "====> (v.3) Tempo de execução: " << delta_us << "ms" << endl << endl;

    return 0;
}

// ********************************************************************
// ********************************************************************
// ********************************************************************
int main() {

    vector<int> v;

    srand ( time(NULL) );

    for (unsigned int i=0; i < MAX; i++) {
        v.push_back(rand() % numeric_limits<int>::max());
    }

	cout << "tamanho do vetor = " << v.size() << endl;

    cout << "conteudo de v: " << endl;
    for (vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
       cout << ' ' << *it << endl;

    minMaxVetor1(v);
    minMaxVetor2(v);
    minMaxVetor3(v);
    	
 	return 0;        
}

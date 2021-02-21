#include <iostream>
#include <string>

using namespace std;

int main() {

    int N; 
    char C, O;

    cin >> N >> C >> O;

    string pkm[N];
    int lvl[N];

    int name, cresc;

    switch ( C ) {
        case 'N': name = 1; break;
        case 'L': name = 0; break;
    }

    switch ( O ) {
        case 'C': cresc = 1; break;
        case 'D': cresc = 0; break;
    }

    for ( int i=0; i<N; i++ ) {

        cin >> pkm[i] >> lvl[i];
    }

    int menor_i, aux;
    string auxs;

    for ( int i=0; i<N-1; i++ ) {

        menor_i = i;

        for ( int j=i+1; i<N; i++ ) {

            if (name) {
                if (cresc) {
                    if ( pkm[j].at(0) < pkm[menor_i].at(0)) {
                        menor_i = j;
                    }
                } else {
                    if ( pkm[j].at(0) > pkm[menor_i].at(0)) {
                        menor_i = j;
                    }
                }
            } else {
                if (cresc) {
                    if ( lvl[j] < lvl[menor_i]) {
                        menor_i = j;
                    }
                } else {
                    if ( lvl[j] > lvl[menor_i]) {
                        menor_i = j;
                    }
                }
            }

            aux = lvl[i];
            lvl[i] = lvl[menor_i];
            lvl[menor_i] = aux;

            auxs = pkm[i];
            pkm[i] = pkm[menor_i];
            pkm[menor_i] = auxs; 
        }
    }

    for ( int i=0; i<N; i++ ) {
        cout << pkm[i] << " " << lvl[i] << endl;
    }
} 
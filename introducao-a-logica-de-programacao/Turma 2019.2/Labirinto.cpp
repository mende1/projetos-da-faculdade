#include <iostream>
#include <string>

using namespace std;

int main() {

  int i, j, n, q, p, esquerda, direita, meio, cont = 0;

  cin>>n;

  int chaves[n];

  for(i=0; i<n; i++){
    cin>>chaves[i];
  }

  cin>>q;

  int portas[q];

  for(i=0; i<q; i++){
    cin>>portas[i];
  }

  for(i=0; i<q; i++){
    p = portas[i];

    esquerda = 0;
    direita = n - 1;

    while(esquerda <= direita){

      meio = (esquerda + direita) / 2;
      if(p < chaves[meio])
        direita = meio - 1;
      else if (p == chaves[meio])
        break;
      else
        esquerda = meio + 1;
    }
    if (p == chaves[meio]){
      cont++;
    }  

  }

  if (cont == q)
    cout<<"Sim"<<endl;
  else
    cout<<"Não"<<endl;

}

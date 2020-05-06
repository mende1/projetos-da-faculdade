#include <iostream>
#include <string>

using namespace std;

int main(){

  int chave, i, j, n, m, esquerda, direita, meio, p, soma_imposto = 0;

  cin>>n;

  string planeta[n];
  int imposto[n], auxiliar[n];

  for(i=0; i<n; i++){
    cin>>planeta[i];
    cin>>imposto[i];
  }

  cin>>p; 

  string han_solo[p];

  for(i=0; i<p; i++){
    cin>>han_solo[i];
  }

  for(i=0; i<p; i++){

   chave = i;

    esquerda = 0;
    direita = n - 1;
    
  while(esquerda <= direita){
      meio = (esquerda + direita) / 2;
     if(han_solo[chave] < planeta[meio])
        direita = meio - 1;
     else if (han_solo[chave] == planeta[meio])
        break;
     else
         esquerda = meio + 1;
    }

    if (han_solo[chave] == planeta[meio])
      soma_imposto = soma_imposto + imposto[meio];
  }

  cout<<soma_imposto<<endl;
  
}

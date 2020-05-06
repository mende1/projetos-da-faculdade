#include <iostream>
#include <string>

using namespace std;

int main(){

  int n, m, i, j, menor_i, aux;

  cin>>n;
  cin>>m;

  int moto[n];

  for(i=0; i<n; i++){
    cin>>moto[i];
  }

  for(i=0; i<n-1; i++){
    menor_i = i;
    for(j=i+1; j<n; j++){
      if(moto[j] < moto[menor_i])
       menor_i = j;
    }
    aux = moto[i];
    moto[i] = moto[menor_i];
    moto[menor_i] = aux;
  }

 int esquerda = 0, direita = n - 1, meio;

 while(esquerda <= direita){
   meio = (esquerda + direita) / 2;
   if(m < moto[meio])
      direita = meio - 1;
    else if(m == moto[meio])
      break;
    else 
      esquerda = meio + 1;
  }

  if(moto[meio] == m)  
    cout<<"Mota na moto"<<endl;
  else
    cout<<"Mota"<<endl;

}

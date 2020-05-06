#include <iostream>
#include <string>

using namespace std;

int main(){

 int n, m, i, j, k;

 cin>>n>>m;

 int matriz[m][3], contador[n+1], auxiliar[n+1];

 for(i=1; i<n+1; i++){
  contador[i]=0;
  auxiliar[i]=i;
 }
 
 for(i=0; i<m; i++){
   for(j=0; j<3; j++){
     cin>>matriz[i][j];
     for(k=1; k<n+1; k++){
       if(matriz[i][j]==k){
         contador[k]++;
       }
     }
   }
 }

  int menor_i, aux, auxiliary;
 for(i=1; i<n; i++){
   menor_i=i;
   for(j=i+1; j<n+1; j++){
     if(contador[j]>contador[menor_i])
     menor_i=j;
     if(contador[j]==contador[menor_i]){
      if(j<menor_i)
       menor_i=j;
      } 
   }
   aux=auxiliar[i];
   auxiliar[i]=auxiliar[menor_i];
   auxiliar[menor_i]=aux;
   auxiliary=contador[i];
   contador[i]=contador[menor_i];
   contador[menor_i]=auxiliary;
 }


 for(k=1; k<n+1; k++)
  cout<<auxiliar[k]<<" ";

cout<<endl;

}

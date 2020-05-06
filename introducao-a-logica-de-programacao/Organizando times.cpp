#include <iostream>
#include <string>

using namespace std;

int main(){

 int n, i, j;

 cin>>n;

 int vetor[n], aux, d3 = 0, nd3 = 0;

 for(i=0; i<n; i++){

  cin>>vetor[i];
    if(vetor[i]%3==0)
     d3++;
  }

  int e3[d3], ne3[n];
 
  int k = 0;
 for(i=0; i<n; i++){
  if(vetor[i]%3==0){
   e3[k]=vetor[i];
   k++;}
 }
int menor_i;
 for(i=0; i<d3-1; i++){
  menor_i=i;
  for(j=i+1; j<d3; j++){
    if(e3[j]>e3[menor_i])
    menor_i=j;
  }
  aux = e3[i];
  e3[i] = e3[menor_i];
  e3[menor_i] = aux;
 }

  int m = d3; 
 for(i=0; i<n; i++){
   if(vetor[i]%3!=0){
     ne3[m]=vetor[i];
     m++;
    }
  } 

   int aux1;
  for(i=d3; i<n-1; i++){
   menor_i=i;
   for(j=i+1; j<n; j++){
    if(ne3[j]<ne3[menor_i])
    menor_i=j;
   }
   aux1 = ne3[i];
   ne3[i] = ne3[menor_i];
   ne3[menor_i] = aux1;
 }

 for(i=0; i<d3; i++){
   cout<<e3[i]<<endl;
 }

  for(i=d3; i<n; i++){
   cout<<ne3[i]<<endl;
 }
 
}

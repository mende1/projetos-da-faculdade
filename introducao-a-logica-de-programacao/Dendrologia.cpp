#include <iostream>
#include <string>

using namespace std;

int main(){

 int n, m, i, j;

 cin>>n>>m;

 string arvore[n], aux0;
 int num[n], aux, menor_i;

 for(i=0; i<n; i++){
   cin>>arvore[i];
   cin>>num[i];
 }

 for(i=0; i<n-1; i++){
   menor_i=i;
   for(j=i+1; j<n; j++){
     if(num[j]>num[menor_i])
       menor_i=j;
     }
     aux=num[i];
     num[i]=num[menor_i];
     num[menor_i]=aux;
     aux0=arvore[i];
     arvore[i]=arvore[menor_i];
     arvore[menor_i]=aux0;  
 }

 for(i=0; i<m; i++)

  cout<<arvore[i]<<endl;
  
}

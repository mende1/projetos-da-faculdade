#include <iostream>

using namespace std;

int main(){

int L, C, i, j;

cin>>L>>C;

int matriz[L][C], somaL[L], somaC[C], somafinal=0;

 for(i=0;i<L;i++){
  for(j=0;j<C;j++){
    cin>>matriz[i][j];
  }
 }

 for(i=0;i<L;i++)
   somaL[i]=0;
 for(j=0;j<C;j++)
   somaC[j]=0;

  for(i=0;i<L;i++){
   for(j=0;j<C;j++){
    somaL[i]+=matriz[i][j];
    somaC[j]+=matriz[i][j];
  }
 }

 for(i=0;i<L;i++){
   if(somaL[i]>somafinal)
    somafinal=somaL[i];
 }

 for(j=0;j<C;j++){
   if(somaC[j]>somafinal)
    somafinal=somaC[j];
 }

 cout<<somafinal<<endl;
} 

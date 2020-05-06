#include <iostream>

using namespace std;

int main(){

int L, C, i, j;

 cin>>L>>C;

 int matriz[L+2][C+2], resultado[L][C];

 for(i=0;i<L+2;i++){
  for(j=0;j<C+2;j++){
    matriz[i][j]=0;
  } 
 }

 for(i=1;i<L+1;i++){
  for(j=1;j<C+1;j++){
   cin>>matriz[i][j]; 
  } 
 }

 for(i=1;i<L+1;i++){
  for(j=1;j<C+1;j++){
    resultado[i][j]=matriz[i][j]+matriz[i+1][j]+matriz[i-1][j]+matriz[i][j+1]+matriz[i][j-1];
  } 
 }

 for(i=1;i<L+1;i++){
  for(j=1;j<C;j++)
   cout<<resultado[i][j]<<" ";
  cout<<resultado[i][j]<<endl;   
 }
} 

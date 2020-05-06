#include <iostream>

using namespace std;

int main(){

 int L, C, i, j;

 cin>>L>>C;

 int matriz[L+1][C+1];

 for(i=0;i<L+1;i++){
  for(j=0;j<C+1;j++){
   matriz[i][j]=0; 
  } 
 }

 for(i=0;i<L;i++){
  for(j=0;j<C;j++){
   cin>>matriz[i][j]; 
  } 
 }

 for(i=0;i<L;i++){
  for(j=0;j<C;j++){
   if((matriz[i][j]+matriz[i+1][j]+matriz[i][j+1]+matriz[i+1][j+1])==4){
    cout<<"PegarMaMarreeta"<<endl;
    return 0;
   }
  } 
 }

for(i=0;i<L;i++){
  for(j=0;j<C;j++){
   if((matriz[i][j]+matriz[i+1][j]+matriz[i][j+1]+matriz[i+1][j+1])!=4){
    cout<<"Dboas"<<endl;
    return 0;
   }
  } 
 }
} 

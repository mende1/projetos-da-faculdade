#include <iostream>

using namespace std;

int main(){

int f, c;

cin>>f>>c;

int i, j, matriz[f][c];

 for(i=0;i<f;i++){
  for(j=0;j<c;j++){

   cin>>matriz[i][j];

  }
 }

 for(i=0;i<f;i++){
  for(j=0;j<c-1;j++){
   if(matriz[i][j]==matriz[i][j+1] && matriz[i][j]==0 && matriz[i][j+1]==0){

    cout<<"Fileira: "<<i+1<<endl;
    cout<<"Assentos: "<<j+1<<" e "<<j+2<<endl;
    return 0;

   }
  }
 }
} 

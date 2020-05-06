#include <iostream>
#include <string>

using namespace std;

int main(){

int i, j, L, C, status = 0;

cin>>L>>C;

int matriz [L+2][C+2];

for(i=0; i<L+2; i++){
 for(j=0; j<C+2; j++){
  matriz[i][j]=0;
 }
}

for(i=1; i<L+1; i++){
 for(j=1; j<C+1; j++){
  cin>>matriz[i][j];
 }
}

for(i=1; i<L+1; i++){
 for(j=1; j<C+1; j++){
  if(matriz[i-1][j]%2!=0 && matriz[i][j-1]%2!=0 && matriz[i+1][j]%2!=0 && matriz[i][j+1]%2!=0)
   status = 1;
 }
}

if(status == 0)
 cout<<"Socorro!"<<endl;

if(status == 1)
 cout<<"Ufa!"<<endl;

}

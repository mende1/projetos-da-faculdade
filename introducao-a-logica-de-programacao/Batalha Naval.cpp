#include <iostream>
#include <string>

using namespace std;

int main(){

int n, m, c, i, j, k, count = 0, contador = 0, x, y;

cin>>n>>m>>c;

int matriz[n][m], tiro[c][2];

for(i=0; i<n; i++){
 for(j=0; j<m; j++){
  cin>>matriz[i][j];
  if(matriz[i][j]==1)
   contador++;
 }
}

int metade;

if(contador%2!=0)
 metade = (contador + 1) / 2;
else{
 metade = contador / 2;
}

for(i=0; i<c; i++){
 for(j=0; j<2; j++){
  cin>>tiro[i][j];
 }
}

  for(k=0; k<c; k++){
   x=tiro[k][0];
   y=tiro[k][1];
   if(matriz[x][y]==1){
    count++;
    matriz[x][y]=0;
 }  
}

if(count>=metade)
 cout<<"Bira"<<endl;

else{
 cout<<"Vidal"<<endl;
}


}

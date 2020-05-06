#include <iostream>

using namespace std;

int main(){

 int n, m, i, j, menorI=200, menorJ=200, maiorI=0, maiorJ=0;
 char x=42;

 cin>>n>>m;

 int matriz[n][m];
 char resultado[n][m];

 for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      cin>>matriz[i][j];
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(matriz[i][j]==1){
      if(i-1<menorI)
       menorI=i-1;
      if(j-1<menorJ)
       menorJ=j-1;
      if(i+1>maiorI)
       maiorI=i+1;
      if(j+1>maiorJ)
       maiorJ=j+1;   
      } 
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      resultado[i][j]=matriz[i][j];
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(resultado[i][j]==0)
       resultado[i][j]=48;
      if(resultado[i][j]==1)
       resultado[i][j]=49; 
    }
  }


  for(i=menorI;i<=menorI;i++){
    for(j=menorJ;j<=maiorJ;j++){
      resultado[i][j]=x;
    }
  }

  for(i=menorI;i<=maiorI;i++){
    for(j=menorJ;j<=menorJ;j++){
      resultado[i][j]=x;
    }
  }

  for(i=maiorI;i<=maiorI;i++){
    for(j=menorJ;j<=maiorJ;j++){
      resultado[i][j]=x;
    }
  }

  for(i=menorI;i<=maiorI;i++){
    for(j=maiorJ;j<=maiorJ;j++){
      resultado[i][j]=x;
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<m-1;j++)
     cout<<resultado[i][j]<<" ";
    cout<<resultado[i][j]<<endl; 
  }
}

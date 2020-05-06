#include <iostream>
#include <string>

using namespace std;

int main(){

 int n, m, i, j, k, tam;

 cin>>n>>m;

 char matriz[n][m];
 int var=0;

 for(i=0;i<n;i++){
   for(j=0;j<m;j++){
     cin>>matriz[i][j];
    }
  }

  char name;
  string nome;

  cin>>nome;

  tam=nome.size();

  int x=n+tam, y=m+tam;

  char palavra[x][y];

  for(i=0;i<x;i++){
    for(j=0;j<y;j++){
      palavra[i][j]=48;
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      palavra[i][j]=matriz[i][j];
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      for(k=0;k<tam;k++){
        if(nome[k]==palavra[i][j])
         var++;
        j++; 
      }
      j=(j-tam);

      if(var==tam){
       cout<<"Sim"<<endl;
       return 0;
      }

      else{var=0;}
    }
  }

for(j=0;j<m;j++){
    for(i=0;i<n;i++){
      for(k=0;k<tam;k++){
        if(nome[k]==palavra[i][j])
         var++;
        i++; 
      }
      i=(i-tam);

      if(var==tam){
       cout<<"Sim"<<endl;
       return 0;
      }

      else{var=0;}
    }
  }

  cout<<"Nao"<<endl;

}

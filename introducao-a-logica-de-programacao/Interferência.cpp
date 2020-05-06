#include <iostream>
#include <string>

using namespace std;

int main(){

 string nome;

 char a=65, b=90;

getline(cin, nome);

int size = nome.size(), i;

for (i=0;i<size;i++){

 if(nome[i]>=a && nome[i]<=b)

  cout<<nome[i];

 }

 cout<<endl;

}

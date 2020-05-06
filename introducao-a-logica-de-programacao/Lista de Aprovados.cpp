#include <iostream>
#include <string>

using namespace std;

int main(){

string nome;

getline(cin, nome);

int i, vagas, status=0;

cin>>vagas;
cin.ignore();

string nome2[vagas];

for(i=0;i<vagas;i++){

 getline(cin, nome2[i]);

}
for(i=0;i<vagas;i++){

 if(nome2[i]==nome)

  status=1;

}

if(status==0)

 cout<<"Vamos esperar a 2a chamada"<<endl;

 if(status==1)

  cout<<"PARABENS"<<endl;

}

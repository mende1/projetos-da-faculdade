#include <iostream>
#include <string>

using namespace std;

int main(){

string nome;

int i,j;

cin>>nome;

int size = nome.size();
string inverso = nome;
j = size-1;

for(i=0;i<size;i++){

inverso[j]=nome[i];
j--;

}

if(nome==inverso){

 cout<<"Sim"<<endl;

}

else{
 
 cout<<"Nao"<<endl;

}

}


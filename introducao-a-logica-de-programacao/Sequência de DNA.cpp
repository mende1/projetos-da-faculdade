#include <iostream>
#include <string>

using namespace std;

int main(){

string dna, doenca;

cin>>dna>>doenca;

int i, size = doenca.size(), resultado=0;

 for(i=0;i<size-2;i++){

   if(dna[0]==doenca[i] && dna[1]==doenca[i+1] && dna[2]==doenca[i+2])
   
    resultado=1;

 }

 if(resultado==0)

  cout<<"Nao possui sequencia"<<endl;

 if(resultado==1) 

  cout<<"Possui sequencia"<<endl;

}

#include <iostream>
#include <string>

using namespace std;

int main(){

 int n, i, j;

 cin>>n;
 cin.ignore();

 string nome[n], letra[n], aux;

 for(i=0; i<n; i++)

  getline(cin, nome[i]);

 for(i=0; i<n-1; i++){
   for(j=i+1; j<n; j++){
     if(nome[j].at(0)<nome[i].at(0)){
       aux=nome[i];
       nome[i]=nome[j];
       nome[j]=aux;
     }
     if(nome[j].at(0)==nome[i].at(0)){
       if(nome[j].at(1)<nome[i].at(1)){
         aux=nome[i];
         nome[i]=nome[j];
         nome[j]=aux;
       }
       if(nome[j].at(1)==nome[i].at(1)){
         if(nome[j].at(2)<nome[i].at(2)){
           aux=nome[i];
           nome[i]=nome[j];
           nome[j]=aux;
         }
       }
     }
   }
 } 

 for(i=0; i<n; i++)

  cout<<nome[i]<<endl;

}

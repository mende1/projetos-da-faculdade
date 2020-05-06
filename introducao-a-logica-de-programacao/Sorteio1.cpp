#include <iostream>

using namespace std;

int main(){

int n,i,maior=0,resultado=0;

cin>>n;

int id[200]={0},v[200]={0};

 for(i=0;i<n;i++){

   cin>>id[i];

  }

 for(i=0;i<n;i++){

   v[id[i]]++;

  }

 for(i=0;i<n;i++){

  if(v[id[i]]>maior){

    maior=v[id[i]];
    resultado=id[i];

  }
 
   if(v[id[i]]==maior){

    if(id[i]>resultado)

      resultado=id[i];
   }
  }

cout<<resultado<<endl;

}

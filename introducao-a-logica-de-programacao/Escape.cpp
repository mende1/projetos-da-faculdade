#include <iostream>
#include <string>

using namespace std;

int main(){

 int n, i, j;

 cin>>n;

 double tempo[n], aux;

 for(i=0; i<n; i++)

  cin>>tempo[i];

 for(i=0; i<n-1; i++){
   for(j=i+1; j<n; j++){
     if(tempo[j]>tempo[i]){
      aux=tempo[i];
      tempo[i]=tempo[j];
      tempo[j]=aux;
     }
   }
 } 

  for(i=0; i<3; i++){

   cout.precision(2);
   cout<<fixed<<tempo[i]<<endl;
  
  }

}

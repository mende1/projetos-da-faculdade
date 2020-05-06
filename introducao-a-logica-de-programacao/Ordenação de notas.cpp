#include <iostream>
#include <string>

using namespace std;

int main(){

 int n, i, j, menor_i;

 cin>>n;

 int nota[n], aux1;
 string aluno[n], aux2;

 for(i=0; i<n; i++){
   cin>>nota[i];
   cin>>aluno[i];
 }

 for(i=0; i<n-1; i++){
   menor_i=i;
   for(j=i+1; j<n; j++){
     if(nota[j]>nota[i])
      menor_i=j;
     if(nota[j]==nota[i]){
       if(aluno[j].at(0)<aluno[i].at(0))
        menor_i=j;
     }
   }
   aux1=nota[i];
   nota[i]=nota[menor_i];
   nota[menor_i]=aux1;
   aux2=aluno[i];
   aluno[i]=aluno[menor_i];
   aluno[menor_i]=aux2;
 }

 for(i=0; i<n; i++){
   cout<<nota[i]<<" "<<aluno[i]<<endl;
 }

}

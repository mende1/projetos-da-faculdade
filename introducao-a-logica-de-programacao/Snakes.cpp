#include <iostream>

using namespace std;

int main(){

 int L, C, i, j;

 cin>>L>>C;

 int matriz[L][C], soma=0;

 for(i=0;i<L;i++){
   for(j=0;j<C;j++){
     cin>>matriz[i][j]; 
   } 
 }

 for(i=0;i<L;i++){
   if(i%2==0){
    for(j=0;j<C;j++){
      soma+=matriz[i][j];
       if(soma<0)
        soma=0;
     } 
   }
   if(i%2!=0){
    for(j=C-1;j>=0;j--){
      soma+=matriz[i][j];
       if(soma<0)
        soma=0;    
     }
   }
 }
 cout<<soma<<endl;
} 

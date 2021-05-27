#include <iostream>
 
using namespace std;
 
int main(){
 
int i,j,C,H,k,t=1,maior=0;
 
int O,D,V[110]={0};
 
  do{
 
 cin>>H>>C;
// Loop para ler de casa de origem e destino dos corvos
 for(i=1;i<=C;i++){
  cin>>O>>D;
  V[O]++;
  V[D]++;
  }
 
 
  for(j=1;j<=H;j++){
   if(V[j]>maior)
     maior=V[j];
   }
 
 if(H!=0&&C!=0)
  cout<<"Teste "<<t<<endl;
 
for(j=1;j<=H;j++){
  if(maior == V[j])
   cout<<j<<" ";
 }
 
  if(H!=0&&C!=0){
   t++;
   cout<<endl<<endl;
   maior=0;
for(j=1;j<=110;j++){
 
 V[j]=0;}
}
 
  else{
    cout<<endl;
   maior=0;
  }
  }
  while(H!=0||C!=0);
 
}

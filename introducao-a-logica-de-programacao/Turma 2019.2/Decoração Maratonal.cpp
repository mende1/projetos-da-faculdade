#include <iostream>
#include <string>

using namespace std;

int main(){

string balao1, balao2;

cin>>balao1>>balao2;

int size1 = balao1.size(), size2 = balao2.size();
int resultado[size2], i, j, x=0;

for(i=0;i<size2;i++){

 resultado[i]=0;

}

for(i=0;i<size2;i++){
 for(j=0;j<size1;j++){

  if(balao2[i]==balao1[j]){

    resultado[i]=1;
    balao1[j]=0;
    break;
  }
 }
}

for(i=0;i<size2;i++){

 x+=resultado[i];

}

if(x==size2)

 cout<<"Eh possivel"<<endl;

else{

 cout<<"Impossivel"<<endl;

} 

}

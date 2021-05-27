#include <iostream>

using namespace std;

int main(){

int s,n;

 cin>>s>>n;

int pedra[n]={0},pulo[s],i,j,x;

for(i=0;i<s;i++){

 cin>>pulo[i];

}


for(i=0;i<s;i++){

 for(j=0;j<n;j+=pulo[i]){

  pedra[j]=1;  
 }
}

for(j=0;j<n;j++){

 cout<<pedra[j]<<" ";
}


cout<<endl;
}

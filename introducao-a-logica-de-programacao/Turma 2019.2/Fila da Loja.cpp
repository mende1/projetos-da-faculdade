#include <iostream>

using namespace std;

int main(){

int n;

cin>>n;

int i,num[n];

for(i=0;i<n;i++){

 cin>>num[i];

}

for(i=0;i<n;i++){

 if(num[i]%2==1)

  cout<<num[i]<<endl;}

for(i=0;i<n;i++){

 if(num[i]%2==0)

  cout<<num[i]<<endl;}

}

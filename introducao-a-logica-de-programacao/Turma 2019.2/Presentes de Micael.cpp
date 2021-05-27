#include <iostream>

using namespace std;

int main(){

int n,i,media=0,mediafinal;
cin>>n;
int num[n];

for(i=0;i<n;i++){
 cin>>num[i];
media+=num[i];
}

for(i=0;i<n;i++){
mediafinal=media/n;
 if(num[i]>=mediafinal)
  cout<<num[i]<<": Sim!";
 else if(num[i]<mediafinal)
  cout<<num[i]<<": Nao!";
cout<<endl;
}
}

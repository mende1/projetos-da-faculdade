#include <iostream>

using namespace std;

int main(){

int n;

cin>>n;

int num[n],i,j;

for(i=0;i<n;i++){

 cin>>num[i];

}

for(i=0;i<n;i++){

j=i-1;

 if(num[j]<=num[i]){

   num[j]=(num[i]+1);

    i=0;

 }
}

for(i=0;i<n;i++){

 cout<<num[i]<<" ";

 }

cout<<endl;

}

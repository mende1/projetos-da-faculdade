#include <iostream>

using namespace std;

int main(){

int n;

cin>>n;

int i,aux,t,x,y;

char name[n];

for(i=0;i<n;i++){

 cin>>name[i];

}


cin>>t;

for(i=0;i<t;i++){

 cin>>x>>y;

 aux=name[x];
 name[x]=name[y];
 name[y]=aux;

}

for(i=0;i<n;i++){

 cout<<name[i];

}

cout<<endl;

}

#include <iostream>
#include <string>

using namespace std;

int main(){

int i, j, n;

cin>>n;

string nome, sobrenome;

 for(i=0; i<n; i++){

  cin>>nome>>sobrenome;

int size1 = nome.size(), media1;
int size2 = sobrenome.size(), media2;

if(size1%2!=0){
media1 = (size1 - 1) / 2;
}
else{
media1 = size1 / 2;
}
if(size2%2!=0){
media2 = (size2 - 1) / 2;
}
else{
media2 = size2 / 2;
}

for(j=0; j<media1; j++){
 cout<<nome.at(j);
}
for(j=media2; j<size2; j++){
 cout<<sobrenome.at(j);
}
cout<<endl;
 }
}

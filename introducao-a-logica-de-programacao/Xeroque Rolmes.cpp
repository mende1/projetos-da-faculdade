#include <iostream>
#include <string>

using namespace std;

int main(){

string nome[6];

int i, size[6];

for(i=0;i<6;i++){

cin>>nome[i];
size[i] = nome[i].size();

}

for(i=0;i<6;i++){

cout<<size[i];

}

cout<<endl;

}


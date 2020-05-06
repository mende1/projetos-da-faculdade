#include <iostream>
#include <string>

using namespace std;

int main(){

int numlivros, maxcons;
char a = 97, z = 122, e = 101, I = 105, o = 111, u = 117;
int size, i, j;

cin >> numlivros >> maxcons;
cin.ignore();

int numcons[numlivros], resultado[numlivros];
string livro[numlivros];

for(i=0;i<numlivros;i++){
  numcons[i]=0;
  resultado[i]=0;
} 

for(i=0;i<numlivros;i++){

  getline(cin, livro[i]);

  size = livro[i].size();

for(j=0;j<size;j++){

 if(livro[i].at(j)>a && livro[i].at(j)<=z && livro[i].at(j)!=e && livro[i].at(j)!=I && livro[i].at(j)!=o && livro[i].at(j)!=u )

   numcons[i]+=1;

 }
}

for(i=0;i<numlivros;i++){

 if(numcons[i]<=maxcons)

   resultado[i]=1;

}

for(i=0;i<numlivros;i++){

 cout<<resultado[i]<<endl;

}

}


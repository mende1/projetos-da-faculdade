#include <iostream>
#include <string>

using namespace std;

int main(){

int n, i;

cin>> n;

string cor;
int media = (n+1)/2, media1 = media - 1;

cin>>cor;

if(cor.at(0)!=cor.at(media1) && cor.at(media1)!=cor.at(n-1) && cor.at(0)!=cor.at(n-1))

 cout<<"Sim"<<endl;

else{

 cout<<"Nao"<<endl;

}


}

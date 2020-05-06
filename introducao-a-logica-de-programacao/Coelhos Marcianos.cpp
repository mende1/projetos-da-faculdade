#include <iostream>

using namespace std;

long int f (int geracao){
  long int r;
  if(geracao==0){
    return 1;
  }  
  r=(f(geracao-1)*3);
  return r;
}

int main(){

  int geracao;

  cin>>geracao;
  
  cout<<f(geracao)-1<<endl;

  return 0;

}

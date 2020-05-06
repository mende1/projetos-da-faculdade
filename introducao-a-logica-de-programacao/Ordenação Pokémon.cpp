#include <iostream>
#include <string>

using namespace std;

int main(){

	int n, i, j;

	cin>>n;
	cin.ignore();

	string pokemon[n];

	for(i=0; i<n; i++)

		getline(cin, pokemon[i]);

	int menor_i;
	string aux;

  for(i=0; i<n-1; i++){

		menor_i = i;

		for(j=i+1; j<n; j++){

			if(pokemon[j]>pokemon[menor_i])

				menor_i = j;

		}

	aux = pokemon[i];
	pokemon[i] = pokemon[menor_i];
	pokemon[menor_i] = aux;

	}

	for(i=0; i<n; i++)

		cout<<pokemon[i]<<endl;

}

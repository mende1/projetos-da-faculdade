#include <iostream>
#include <string>

using namespace std;

int main(){

	int n, i, j, menor_i, aux;
	string aux1;

	cin>>n;

	string pokemon[n];
	int forca[n], poder[n];

	for(i=0; i<n; i++){

		cin>>pokemon[i];
		cin>>forca[i];
		cin>>poder[i];

	}

	for(i=0; i<n-1; i++){

		menor_i = i;

		for(j=i+1; j<n; j++){

			if(poder[j] > poder[menor_i])

				menor_i = j;

			if(poder[j] == poder[menor_i]){

				if(forca[j] > forca[menor_i])

					menor_i = j;

			}
		
		}

	aux = poder[i];
	poder[i] = poder[menor_i];
	poder[menor_i] = aux;

	aux = forca[i];
	forca[i] = forca[menor_i];
	forca[menor_i] = aux;

	aux1 = pokemon[i];
	pokemon[i] = pokemon[menor_i];
	pokemon[menor_i] = aux1;

	}

	for(i=0; i<n; i++){

		cout<<pokemon[i]<<" "<<poder[i]<<endl;

	}

}

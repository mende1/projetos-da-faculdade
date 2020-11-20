#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> vet;

int main(){

	int n, i, var, count = 0;

	cin >> n;

	for (i=0; i<n; i++){

		cin >> var;

		vet.push_back(var);

	}

	stable_sort(vet.begin(), vet.end());

	for (i=0; i<n; i++){

		if (i != n - 1){

			if (vet[i+1] != vet[i] + 1){

				vet.push_back(vet[i]+1);

				stable_sort(vet.begin(), vet.end());

				n += 1;
				count += 1;

			}

		}

	}

	cout << count << endl;

}

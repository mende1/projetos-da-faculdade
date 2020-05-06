#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int i, j, k, num;
	
	cin >> j >> k;
	
	vector <int> vet;
	
	for (i=0; i<j; i++){
	
		cin >> num;
		
		vet.push_back(num);
	
	}
	
	stable_sort(vet.rbegin(), vet.rend());
	
	for (i=0; i<k; i++)
	
		cout << vet[i] << endl;
	
}
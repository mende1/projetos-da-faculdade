#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(){

	int n, num;
	
	cin >> n;
	
	vector<int>vet;
	
	for (int i=0; i<n; i++){
	
		cin >> num;
		
		vet.push_back(num);
		
	}
	
	int k, count = 0;
	
	cin >> k;
	
	vector<int>::iterator it;
	
	for (it = vet.begin(); it < vet.end(); it+=k)
	
		count += *it;
	
	cout << count << endl;
	
}


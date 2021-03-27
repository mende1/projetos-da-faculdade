#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
 
	vector<int> vet(3);
 
	for (int i=0; i<3; i++) {
		cin >> vet[i];
	}
 
	sort(vet.begin(), vet.end());
 
	cout << (vet[1] - vet[0]) + (vet[2] - vet[1]) << endl;
	
}
 
int main(){
 
	int t = 1;
 
	while (t) {
		solve();
		t--;
	}
}

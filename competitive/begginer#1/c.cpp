#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
 
	int n;
	cin >> n;
 
	vector<int> vet;
 
	for (int i=0; i<n; i++) {
		int aux;
		cin >> aux;
		vet.push_back(aux);
	}
 
	sort(vet.begin(), vet.end());
 
	int min = vet[1] - vet[0];
 
	for (int i=1; i<n-1; i++) {
		if ((vet[i+1] - vet[i]) < min) {
			min = vet[i+1] - vet[i];
		}
	}
 
	cout << min << endl;
}
 
int main(){
 
	int t; 
	cin >> t;
 
	while (t) {
		solve();
		t--;
	}
}

#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
 
	int n, k;
	cin >> n >> k;
 
	vector<int> a,b;
 
	for (int i=0; i<n; i++) {
		int aux;
		cin >> aux;
		a.push_back(aux);
	}
 
	for (int i=0; i<n; i++) {
		int aux;
		cin >> aux;
		b.push_back(aux);
	}
 
	int sum = 0;
 
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
 
	int i=0, j=n-1;
	while (k) {
		
		if (b[j] > a[i]) {
			int aux = a[i];
			a[i] = b[j];
			b[j] = aux;
		} else {
			break;
		}
 
		i++; j--;
 
		k--;
	}
 
	for (int i=0; i<n; i++) {
		sum += a[i];
	}
 
	cout << sum << endl;
 
}
 
int main(){
 
	int t; 
	cin >> t;
 
	while (t) {
		solve();
		t--;
	}
}

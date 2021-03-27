#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
 
	int n;
	cin >> n;
 
	set<int> set;
 
	for (int i=0; i<n; i++) {
		int aux;
		cin >> aux;
		set.insert(aux);
	}
 
	int sum = set.size() - set.count(0);
 
	cout << sum << endl;
}
 
int main(){
 
	int t = 1;
 
	while (t) {
		solve();
		t--;
	}
}

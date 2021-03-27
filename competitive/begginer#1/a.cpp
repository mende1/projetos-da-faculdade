#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
 
	int c; cin >> c;
 
	vector<int> vet;
 
	for (int j=0; j<c; j++) {
		int a;
		cin >> a;
		vet.push_back(a);
	}
 
	sort(vet.begin(), vet.end());
 
	bool ok = true;
 
	for (int j=0; j<c-1; j++) {
 
		if (vet[j+1] - vet[j] > 1) {
			ok = false;
		}
	}
 
	if (ok) cout << "YES\n";
	else cout << "NO" << endl;
}
 
int main(){
 
	int t; cin >> t;
 
	while (t) {
		solve();
		t--;
	}
}

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define fori(x, n) for(int i=x; i<int(n); i++)
#define forj(x, n) for(int j=x; j<int(n); j++)
#define fork(x, n) for(int k=x; k<int(n); k++)
 
#define cins(s) string s; cin>>s;
#define cini(i) int i; cin>>i;
#define cind(d) double d; cin>>d;
#define cinvi(a, n) vi a(n); fori(0, n) { cin>>a[i]; }
#define cinvs(s, n) vs s(n); fori(0, n) { cin>>s[i]; }
#define cinvd(a, n) vd a(n); fori(0, n) { cin>>a[i]; }
 
typedef vector<double>   vd;
typedef vector<bool>     vb;
typedef vector<int>      vi;
typedef vector<vi>      vvi;
typedef vector<string>   vs;
 
 
 
 
void solve() {
	// ----------------------------
 
    cini(n);
	int arr[n], ans[101];
 
	fori(0, 101) {
		ans[i] = 0;
	}
 
	fori(0, n) {
		cin >> arr[i];
		ans[arr[i]]++;
	}
 
	fori(0, n) {
		if (ans[arr[i]] == 1) {
			cout << i+1 << endl;
			return;
		}
	}
 
	// ----------------------------
}
 
int main(){
 
	cini(t);
	// int t = 1;
 
	while (t--) {
		solve();
	}
}

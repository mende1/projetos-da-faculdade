#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fori(x, n) for(int i=x; i<int(n); i++)
#define forj(x, n) for(int j=x; j<int(n); j++)

#define cins(s) string s; cin>>s;
#define cini(i) int i; cin>>i;
#define cind(d) double d; cin>>d;
#define cinvi(a, n) vi a(n); fori(0, n) { cin>>a[i]; }
#define cinvs(s, n) vs s(n); fori(0, n) { cin>>s[i]; }
#define cinvd(a, n) vd a(n); fori(0, n) { cin>>a[i]; }

typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

void solve() {

	cini(n);

	map<string, int> map;

	fori(0, n) {
		cins(aux);
		if(map.find(aux) != map.end()){
			map[aux] = map[aux]+1;
			cout << aux << map[aux] << endl;
		}
		else {
			cout << "OK" << endl;
			map.insert(make_pair(aux, 0));
		}
	}
}

int main(){

	int t=1;

	while (t--) {
		solve();
	}
}

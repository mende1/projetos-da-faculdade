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
	cinvi(fila, n);

	cini(m);
	cinvi(saiu, m);

	fori(0, m) {
		forj(0, n) {
			if (fila[j] == saiu[i]) {
				fila[j] = 0;
				break;
			}
		}
	}

	vi res;

	fori(0, n) {
		if(fila[i]) {
			res.push_back(fila[i]);
		}
	}

	fori(0, res.size()) {
		cout << res[i] << " ";
	}
	cout << endl;
}

int main(){

	int t = 1;

	while (t--) {
		solve();
	}
}

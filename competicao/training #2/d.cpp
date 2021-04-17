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

	cini(n); cini(m);

	map<string, string> serv;

	fori(0, n) {
		cins(str);
		cins(ip);

		serv.insert(make_pair(ip, str));
	}

	fori(0, m) {
		cins(str);
		cins(ip);

		string oldIp = ip;

		ip.pop_back();

		string newIp = oldIp + " #" + serv[ip];

		cout << str << " " << newIp << endl;
	}
	
}

int main(){

	// cini(t);
	int t=1;

	while (t--) {
		solve();
	}
}

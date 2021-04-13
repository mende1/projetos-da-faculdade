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




void solve(ll t) {
	// ----------------------------

	priority_queue<ll, vector<ll>, greater<ll>> pq;

	fori(0, t) {
		ll b; cin >> b;
		pq.push(b);
	}

	ll sum = 0, ans;
	sum = pq.top();
	pq.pop();
	sum += pq.top();
	pq.pop();
	ans = sum;

	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
		ans += sum;
	}

	cout << ans << endl;

	// ----------------------------
}

int main(){

	// cini(t);
	ll t;

	while (cin >> t && t) {
		solve(t);
	}
}

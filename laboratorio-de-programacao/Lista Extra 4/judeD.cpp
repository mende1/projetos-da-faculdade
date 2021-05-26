#include <iostream>
#include <list>
#define endl "\n"
#define cini(n) int n; cin >> n;

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cini(n);
	list<int> mylist;

	for (int i=0; i<n; i++) {
		cini(a);
		mylist.push_back(a);
	}

	int max = mylist.back();

	cini(r);

	for (int i=0; i<r; i++) {
		cini(m);

		for (int j=0; j<m; j++) {
			cini(b);
			mylist.remove(b);
		}

		int left = true;

		while (mylist.size() < n) {
			if (left) {
				mylist.push_front(++max);
			}
			else {
				mylist.push_back(++max);
			}

			left = not left;
		}
	}

	for (auto it : mylist) {
		cout << it << " ";
	}

	cout << endl;
}
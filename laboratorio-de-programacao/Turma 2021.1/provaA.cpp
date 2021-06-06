#include <iostream>
#include <stack>

using namespace std;

int main() {
	
	int n;
	cin >> n;

	stack<int> me, foe;

	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		me.push(a);
	}

	for (int i=0; i<n; i++) {
		int b;
		cin >> b;
		foe.push(b);
	}

	while (!me.empty() && !foe.empty()) {
		int saveMe = me.top();
		me.top()  -= foe.top();
		foe.top() -=  saveMe;

		cout << me.top() << endl << foe.top() << endl << endl;

		if (me.top()  <= 0)  me.pop();
		if (foe.top() <= 0) foe.pop();
	}

	if (me.empty()) {
		cout << "Adversario " << n - foe.size() << endl;
	}
	else if (foe.empty()) {
		cout << "Eu " << n - me.size() << endl;
	}
}
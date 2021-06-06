#include <iostream>
#include <list>

using namespace std;

typedef struct TStudent {
	int power;
	string name;
} TStudent;

bool comparePower (const TStudent &a, const TStudent &b) {
	return (a.power < b.power);
}

int main() {
	
	int n;
	cin >> n;

	list<TStudent> gryffindor, slytherin;

	for (int k=0; k<n; k++) {
		int g, s, m;
		cin >> g >> s >> m;

		for (int i=0; i<g; i++) {
			TStudent a;
			cin >> a.power;
			cin.ignore();
			getline(cin, a.name);

			gryffindor.push_back(a);
		}

		for (int i=0; i<s; i++) {
			TStudent b;
			cin >> b.power;
			cin.ignore();
			getline(cin, b.name);
			slytherin.push_back(b);
		}

		gryffindor.sort(comparePower);
		slytherin.sort(comparePower);

		for (int i=0; i<m; i++) {
			if (gryffindor.empty() || slytherin.empty()) break;
			cout << gryffindor.back().name << " e " << slytherin.front().name << endl;
			gryffindor.pop_back();
			slytherin.pop_front(); 
		}
	}
}
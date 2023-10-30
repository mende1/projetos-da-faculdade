#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define fori(a, n) for(long long i=a; i<n; i++)

using namespace std;

struct Elf {
	string name;
	int age;
	int weight;
	float height;

	bool operator<(const Elf& another) const {
		if (weight != another.weight) {
			return weight > another.weight;
		}

		if (age != another.age) {
			return age < another.age;
		}

		if (height != another.height) {
			return height < another.height;
		}

		return name < another.name;
	};
};

int main() {
	int tc = 0;
	int t; cin >> t;

	while (++tc <= t) {
		
		int n, m;
		cin >> n >> m;

		vector<Elf> elves(n);

		fori (0, n) {
			Elf elf;
			cin >> elf.name >> elf.weight >> elf.age >> elf.height;

			elves[i] = elf;
		}

		sort(elves.begin(), elves.end());

		cout << "CENARIO {" << tc << "}" << endl;

		fori (0, m) {
			cout << i + 1 << " - " << elves[i].name << endl;
		}
	}
}
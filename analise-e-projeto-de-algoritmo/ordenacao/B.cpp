#include <iostream>
#include <string>
#include <vector>

#define fori(a, n) for(int i=a; i<n; i++)

using namespace std;

struct Student {
	string name;
	string color;
	char size;

	bool operator<(const Student& another) const {
		if (color != another.color) {
			return color < another.color;
		}

		if (size != another.size) {
			return size > another.size;
		}
		
		return name < another.name;
	};
};

int main() {
	int n;
	bool new_line = false;

	while (cin >> n && n > 0) {
		if (new_line) cout << endl;

		vector<Student> arr;

		fori (0, n) {
			Student student;

			cin.ignore();
			getline(cin, student.name);
			cin >> student.color;
			cin >> student.size;

			arr.push_back(student);
		}

		sort(arr.begin(), arr.end());

		for (Student student : arr) {
			cout << student.color << " " << student.size << " " << student.name << endl;
		}

		new_line = true;
	}
}
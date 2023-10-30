	#include <iostream>
	#include <algorithm>
	#include <vector>

	#define fori(a, n) for(int i=a; i<n; i++)

	using namespace std;

	struct Team {
		int points = 0;
		int scored = 0;
		int allowed = 0;
		int id;

		float average() const {
			if (!allowed) return scored;

			return (float)scored / allowed;
		}

		bool operator<(const Team& another) const {

			if (points != another.points) {
				return points > another.points;
			}

			if (average() != another.average()) {
				return average() > another.average();
			}
			
			if (scored != another.scored) {
				return scored > another.scored;
			}

			return id < another.id;
		};
	};

	int main() {
		bool new_line = false;
		
		int h = 1, n;

		while (cin >> n && n > 0) {
			if (new_line) cout << endl;

			vector<Team> arr(n);

			fori (0, n) {
				arr[i].id = i + 1;
			}

			int n_of_lines = (n * (n-1)) / 2;

			fori (0, n_of_lines) {
				int x, y, z, w;
				cin >> x >> y >> z >> w;

				x--;
				z--;

				arr[x].scored += y;
				arr[x].allowed += w;

				arr[z].scored += w;
				arr[z].allowed += y;

				if (y > w) {
					arr[x].points += 2;
					arr[z].points += 1;
				} else {
					arr[z].points += 2;
					arr[x].points += 1;
				}
			}

			sort(arr.begin(), arr.end());

			cout << "Instancia " << h++ << endl;
			
			fori (0, n) {
				cout << arr[i].id;

				if (i != n-1) {
					cout << " ";
				}
			}

			cout << endl;

			new_line = true;
		}
	}
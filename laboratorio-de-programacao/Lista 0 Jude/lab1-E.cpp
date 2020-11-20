#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct guerreiro {

	string name;
	int power;

};

bool cmp(guerreiro a, guerreiro b){

	return (a.power < b.power || (a.power == b.power && a.name < b.name));

}

int main(){

	int i, j, k, var2;

	string var1;

	cin >> j >> k;

	vector <guerreiro> warrior;
	guerreiro var;

	for (i=0; i<j; i++){

		cin >> var.name;
		cin >> var.power;

		warrior.push_back(var);

	}

	stable_sort(warrior.rbegin(), warrior.rend(), cmp);

	for (i=0; i<k; i++){

		cout << warrior[i].name << " ";
		cout << warrior[i].power << endl;

	}

}

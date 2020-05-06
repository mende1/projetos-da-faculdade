#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct person{

	string name;
	int age;
	int id;
	int year;

} tPerson;

bool cmp (const tPerson& p1, const tPerson& p2){

	return (p1.year < p2.year || p1.year == p2.year && (p1.age < p2.age || p1.age == p2.age && p1.id < p2.id));

}

vector <tPerson> people
{

	{"Maria", 17, 8, 2001},
	{"Joao", 17, 2, 2001},
	{"Antonio", 13, 3, 2003},
	{"Carlos", 13, 4, 2003},
	{"Gustavo", 31, 5, 2004},
	{"Rikelme", 36, 6, 2004},
	{"Brenno", 17, 7, 2002},

};

int main(){

	sort(people.begin(), people.end(), cmp);

	cout << "*\n";

	for (const auto& p : people){

		cout << "* nome=" << p.name << "\tidade=" << p.age << "\tid=" << p.id << "\tyear=" << p.year << endl;

	}

	cout << "*\n";

}


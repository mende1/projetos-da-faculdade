#include <iostream>
#include <queue>
#define endl "\n"
#define cini(n) int n; cin >> n;

using namespace std;

typedef struct {
	string name;
	char gender;
} Person;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cini(n);

	queue<Person> male;
	queue<Person> female;
	queue<Person> aux;

	for (int i=0; i<n; i++) {
		Person person;
		cin >> person.name >> person.gender;

		female.push(person);
	}

	for (int i=0; i<n; i++) {
		Person person;
		cin >> person.name >> person.gender;

		male.push(person);
	}

	int sizeF = female.size();
	int sizeM = male.size();

	for (int i=0; i<sizeF; i++) {
		if (female.front().gender == 'M') {
			female.push(female.front());
			female.pop();
		}
		else {
			aux.push(female.front());
			female.pop();
		}
	}

	for (int i=0; i<sizeM; i++) {
		if (male.front().gender == 'H') {
			male.push(male.front());
			male.pop();
		}
		else {
			female.push(male.front());
			male.pop();
		}
	}

	int sizeA = aux.size();

	for (int i=0; i<sizeA; i++) {
		male.push(aux.front());
		aux.pop();
	}

	int newSizeF = female.size();
	int newSizeM = male.size();

	cout << "Fila Feminina:" << endl;

	if (female.empty()) {
		cout << "Vazia" << endl;
	}

	for (int i=0; i<newSizeF; i++) {
		cout << female.front().name << endl;
		female.pop();
	}

	cout << "Fila Masculina:" << endl;

	if (male.empty()) {
		cout << "Vazia" << endl;
	}

	for (int i=0; i<newSizeM; i++) {
		cout << male.front().name << endl;
		male.pop();
	}
}
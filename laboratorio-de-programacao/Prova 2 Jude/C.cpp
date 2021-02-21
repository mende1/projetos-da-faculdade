#include <iostream>
#include <string.h>

using namespace std;

void inverteP(char *s) {

	char ch, *pc;
	int t = strlen(s);

	pc = s+(t-1);

	while (pc > s) {

		ch = *pc;
		*pc = *s;
		*s = ch;

		s++;
		pc--;
	}

}
int main () {

	char palavra[10];

	cin >> palavra;

	inverteP(palavra);

	cout << palavra << endl;

	return 0;
}
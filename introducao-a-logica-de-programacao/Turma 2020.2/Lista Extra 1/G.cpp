#include <iostream>
#include <string>

using namespace std;

string states[6] = {
	"Rio Grande do Sul", "Santa Catarina", "Paraná",
	"Goiás", "Mato Grosso", "Mato Grosso do Sul"
};

int main() {

	string name;
	getline(cin, name);

	int ans = 0;

	for (int i=0; i<6; i++) {
		string aux;
		getline(cin, aux);

		for (int i=0; i<6; i++) {
			if (aux == states[i]) {
				ans++;
				states[i] = "";
			}
		}
	}

	cout << name << " sua pontuação é de " << ans << " pontos.\n";
}
#include <iostream>
#include <string>

using namespace std;
 
int main() {

    int k; cin >> k;

    string name; cin >> name;

    for (int i = 0; i < name.size(); i++) {
    	
    	int aux;

    	if ((int)(name.at(i)) + k > 122) 
    		aux = (int)(name.at(i)) + k - 26;
    	else 
    		aux = (int)(name.at(i)) + k;
    	
    	char novaLetra = aux;

        name.at(i) = novaLetra;
    }

    cout << name << endl;
}
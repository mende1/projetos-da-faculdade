#include <iostream>
#include <vector>

using namespace std;

int main(){

	string list1;
	string list2;

	cin >> list1 >> list2;

	vector <int> var1;

	while (var1.size() < list2.size()){

		var1.push_back(0);

	}

	int i, j, count = 0;

	for (i=0; i<list1.size(); i++){

		for (j=0; j<list2.size(); j++){

			if (list1[i] == list2[j]){

				var1[i] = 1;

				list2[j] = '-';

				break;

			}

		}

	}

	for (i=0; i<var1.size(); i++){

		count += var1[i];

	}

	if (count == list2.size())

		cout << "Sim\n";

	else

		cout << "Nao\n";

}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct data {

	int dia;
	int mes;
	int ano;

} tData;

bool cmp(const tData& d1, const tData& d2){

	return d1.ano < d2.ano || d1.ano == d2.ano && (d1.mes < d2.mes || d1.mes == d2.mes && d1.dia < d2.dia);

}

int main(){

	tData var;
	vector <tData> data;

	while(cin >> var.dia >> var.mes >> var.ano){

		data.push_back(var);

	}

	stable_sort(data.begin(), data.end(), cmp);

	vector <tData> ::iterator it;

	for (it = data.begin(); it != data.end(); it++)

		cout << (*it).dia << " " << (*it).mes << " " << (*it).ano << "\n"; 

}

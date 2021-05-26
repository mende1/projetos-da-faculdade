#include <iostream>

using namespace std;

int calcula (int * dd, int * mm, int * aaaa) {
	
	int idade, diaAtual=18, mesAtual=10, anoAtual=2020;

	// Minha função
	int dias, carryDias = 0;

	if ((diaAtual - *dd) < 0) {
		dias = 30 + (diaAtual - *dd);
		carryDias = 1;
	} else {
		dias = (diaAtual - *dd);
	}
		
	int meses, carryMeses = 0;

	if ((mesAtual - *mm - carryDias) < 0) {
		meses = 12 + (mesAtual - *mm - carryDias);
		carryMeses = 1;
	} else {
		meses = (mesAtual - *mm - carryDias);
	}

	int anos = (anoAtual - *aaaa - carryMeses);

	*dd = anos * 360 + meses * 30 + dias;
	*mm = anos * 12  + meses;

	idade = anos;
	// Final da minha função

	return idade;
}

int main () {

	int dia, mes, ano;

	cin >> dia >> mes >> ano;

	ano = calcula (&dia, &mes, &ano); //pode alterar o que estah em vermelho

	cout << ano << " anos OU " << mes << " meses OU " << dia << " dias" << endl;

	return 0;
}
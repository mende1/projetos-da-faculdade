#include <iostream>

// ***********************************************
// ***********************************************
// ***********************************************

int main() {

int dia, mes, ano;

	std::cout << "\tDatas\n\t=====";
	
	std::cout << "\n\nForneca uma data no formato: (dd mm [-]aaaa) \n\tData = ";	
	std::cin >> dia >> mes >> ano;

	std::cout << "\nA data fornecida foi: " << dia <<
				 " / " << mes << " / " << ano << std::endl; 

	return 0;
}

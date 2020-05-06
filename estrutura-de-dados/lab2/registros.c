/* Tipos Abstratos e Registros */ 

#include<stdio.h>

typedef struct data		{ 	int dia; 	
							int mes; 
							int ano;
						} tData;

				
// ***********************************************
// ***********************************************
// ***********************************************

int main() {

tData	d;	

	printf("\t\tDatas\n\t\t=====");
	
	printf("\n\nForneca uma data no formato:\n\tDia = ");	
	scanf("%d", &d.dia);
	
	printf("\n\n\tMes = ");	
	scanf("%d", &d.mes);
	
	printf("\n\n\tAno = ");	
	scanf("%d", &d.ano);
	
	printf("\n\n\nA data fornecida foi: %d/%d/%d\n", d.dia, d.mes, d.ano); 
	
	return 0;
}

/* Tipos Abstratos e Registros */ 

#include <stdio.h>
#include <stdlib.h>

typedef struct data		{ 	

	int dia; 	
	int mes; 
	int ano;
	int total;

} tData;

typedef struct periodo	{

	tData data_inicio;
	tData data_fim;
	int total_dias;

} tPeriodo;


int main() {

tData	d1, d2;	

	printf("\t\tDatas\n\t\t=====");
	
	printf("\n\nForneça a primeira data válida no formato:\n\tDia (DD) = ");	
	scanf("%d", &d1.dia);

	while(d1.dia < 1 || d1.dia > 30){
	
		printf("Dia inválido, tente novamente.");
	
		printf("\n\tDia (DD) = ");	
		scanf("%d", &d1.dia);
		
	}
	
	printf("\n\n\tMes (MM) = ");	
	scanf("%d", &d1.mes);
	
	while(d1.mes < 1 || d1.mes > 12){
	
		printf("Mês inválido, tente novamente.");
	
		printf("\n\tMês (MM) = ");	
		scanf("%d", &d1.mes);
		
	}
	
	printf("\n\n\tAno (AAAA) = ");	
	scanf("%d", &d1.ano);
	
	while(d1.ano < 1 || d1.ano > 9999){
	
		printf("Ano inválido, tente novamente.");
	
		printf("\n\tAno (AAAA) = ");	
		scanf("%d", &d1.ano);
		
	}
	
	printf("\n\nForneça a segunda data válida no formato:\n\tDia (DD) = ");	
	scanf("%d", &d2.dia);

	while(d2.dia < 1 || d2.dia > 30){
	
		printf("Dia inválido, tente novamente.");
	
		printf("\n\tDia (DD) = ");	
		scanf("%d", &d2.dia);
		
	}
	
	printf("\n\n\tMes (MM) = ");	
	scanf("%d", &d2.mes);
	
	while(d2.mes < 1 || d2.mes > 12){
	
		printf("Mês inválido, tente novamente.");
	
		printf("\n\tMês (MM) = ");	
		scanf("%d", &d2.mes);
		
	}
	
	printf("\n\n\tAno (AAAA) = ");	
	scanf("%d", &d2.ano);
	
	while(d2.ano < 1 || d2.ano > 9999){
	
		printf("Ano inválido, tente novamente.");
	
		printf("\n\tAno (AAAA) = ");	
		scanf("%d", &d2.ano);
		
	}
	
	printf("\n\nA primeira data fornecida foi: %02d/%02d/%04d\n", d1.dia, d1.mes, d1.ano);
	printf("A segunda data fornecida foi: %02d/%02d/%04d\n", d2.dia, d2.mes, d2.ano);

	tPeriodo p;

	p.data_inicio.dia = d1.dia;
	p.data_inicio.mes = d1.mes;
	p.data_inicio.ano = d1.ano;

	p.data_fim.dia = d2.dia;
	p.data_fim.mes = d2.mes;
	p.data_fim.ano = d2.ano;

	p.data_inicio.total = 0;
	p.data_fim.total = 0;

	p.data_inicio.total += 365 * (p.data_inicio.ano);
	p.data_fim.total += 365 * (p.data_fim.ano);

	p.data_inicio.total += 30 * (p.data_inicio.mes);
	p.data_fim.total += 30 * (p.data_fim.mes);

	p.data_inicio.total += 1 * (p.data_inicio.dia);
	p.data_fim.total += 1 * (p.data_fim.dia);

	p.total_dias = abs(p.data_fim.total - p.data_inicio.total);

	printf("\nA diferença entres as datas é de %d dias.\n", p.total_dias);

	return 0;

}

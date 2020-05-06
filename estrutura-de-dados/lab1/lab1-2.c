#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	int n, i, j;
	
		printf("Quantidade de cidades: ");
		scanf("%d", &n);
	
	int city[n][n];
	
		srand(time(NULL));
	
	for (i=0; i<n; i++){
	
		for (j=0; j<n; j++){
		
			if (i != j)
			
				city[i][j] = rand() % 101;
			
			else
			
				city[i][j] = 0;
		}
	
	}
	
	printf("Essa é a relação de preço de viagens entre cidades: (em R$)\n");
	printf("[Viagens dentro da mesma cidade são de graça]\n\n");
	
	for (i=0; i<n; i++){
	
		if (i == 0)
		
			printf("  Destino [%d] ", i);
			
		else if (i != (n-1)){
		
			if (i < 10)
			
				printf("[%d] ", i);
				
			else
			
				printf("[%d]", i);
			
		}
			
		else
		
			printf("[%d]\nSaída\n", i);
	
	}
	
	for (i=0; i<n; i++){
	
		for (j=0; j<n-1; j++){
		
			if (j == 0){
			
				if (i < 10)
			
					printf("[%d]       ", i);
					
				else
				
					printf("[%d]      ", i);
			
			}
		
			if (city[i][j] >= 0 && city[i][j] < 10)
			
				printf("%d   ", city[i][j]);
			
			else if (city[i][j] >= 10 && city[i][j] < 100)
			
				printf("%d  ", city[i][j]);
				
			else
			
				printf("%d ", city[i][j]);
			
		}
			
		printf("%d\n", city[i][j]);	
	
	}
	
	printf("\n");
	
	printf("Você tem a opção de viajar por %d cidades.\n", n);
		
	for (i=0; i<n; i++){
		
		if (i == 0)
		
			printf("Cidades: (%d, ", i);
			
		else if (i == (n-1))
		
			printf("%d).\n", i);
			
		else
		
			printf("%d, ", i);
	
	}
	
	
		int k, count = 0;
		
	printf("Deseja fazer quantas viagens? ");
	scanf("%d", &k);
	
		int viagem[k+1];
		
	printf("Neste momento, você está em qual cidade? ");
	scanf("%d", &viagem[0]);
	
	printf("Digite em ordem, separados por um espaço, por quais cidades quer viajar: ");
	
	for (i=1; i<k+1; i++)
	
		scanf("%d", &viagem[i]);
		
	for (i=0; i<k+1; i++){
	
		if (i != k){
		
			printf("Custo de viagem da cidade %d para %d: R$ %d,00\n", viagem[i], viagem[i+1], city[viagem[i]][viagem[i+1]]);
			count += city[i][i+1];
			
		}

	}
	
	printf("\nVocê fez um total de %d viagens.\n", k);
	printf("O valor gasto total com viagens foi: R$ %d,00.\n", count);

}


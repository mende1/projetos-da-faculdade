#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	int i, j, n = 8;
	
	int dama[n][n];
	
	for (i=0; i<n; i++){
	
		for (j=0; j<n; j++){
		
			dama[i][j] = 0;
		
		}
	
	}
	
	for (i=0; i<n; i++){
	
		if (i % 2 == 0){
		
			dama[0][i] = -1;
			dama[2][i] = -1;
			dama[6][i] = 1;
			
		}
			
		
		if (i % 2 != 0){
		
			dama[1][i] = -1;
			dama[5][i] = 1; 
			dama[7][i] = 1;
			
		}
	
	}
	
	printf("\n\t\t!!! Que comece o jogo de damas !!! \n\n");
	printf("[ -1 para pretas / 1 para brancas / 0 para vazios ]\n");
	printf("O jogo começou da seguinte maneira: \n\n");
	
	for (i=0; i<n; i++){
	
		for (j=0; j<n-1; j++)
		
			if (dama[i][j] == -1)
			
				printf("%d ", dama[i][j]);
			
			else
			
				printf(" %d ", dama[i][j]);
				
		if (dama[i][j] == -1)
			
				printf("%d\n", dama[i][j]);
			
			else
			
				printf(" %d\n", dama[i][j]);
	
	}
	
	printf("\nVocê está com as pedras PRETAS!\n");
	printf("Me informe como está o jogo no momento, e lhe passarei informações úteis para te ajudar.\n");
	
	printf("\nDigite a matriz: [8x8] \n");
	
	int qnt1 = 0, qnt2 = 0, qnt3 = 0;
	int dama1[n+2][n+2];
	
	for (i=0; i<n+2; i++){
	
		for (j=0; j<n+2; j++){
		
			dama1[i][j] = 2;
		
		}

	}
	
	for (i=1; i<n+1; i++){
	
		for (j=1; j<n+1; j++){
		
			scanf("%d", &dama1[i][j]);
		
		}
	
	}
	
	for (i=1; i<n+1; i++){
	
		for (j=1; j<n+1; j++){
		
			if(dama1[i][j] == -1 && ((dama1[i+1][j+1] == 1 && dama1[i+2][j+2] == 0) || (dama1[i+1][j-1] == 1 && dama1[i+2][j-2] == 0) || (dama1[i-1][j+1] == 1 && dama1[i-2][j+2] == 0) || (dama1[i-1][j-1] == 1 && dama1[i-2][j-2] == 0)))
			
				qnt1++;
				
			else if (dama1[i][j] == -1 && (dama1[i+1][j+1] != 0 && dama1[i+1][j-1] != 0))
			
				qnt3++;
				
			else if (dama1[i][j] == -1 && (dama1[i+1][j+1] == 0 || dama1[i+1][j-1] == 0))
			
				qnt2++;
		
		}
	
	}
	
	int peda1[qnt1][2], peda2[qnt2][2], peda3[qnt3][2];
	
	int k = 0, l = 0, m = 0;
	
	for (i=1; i<n+1; i++){
	
		for (j=1; j<n+1; j++){
		
			if(dama1[i][j] == -1 && ((dama1[i+1][j+1] == 1 && dama1[i+2][j+2] == 0) || (dama1[i+1][j-1] == 1 && dama1[i+2][j-2] == 0) || (dama1[i-1][j+1] == 1 && dama1[i-2][j+2] == 0) || (dama1[i-1][j-1] == 1 && dama1[i-2][j-2] == 0))){
			
				peda1[k][0] = i;
				peda1[k][1] = j;
				
				k++;
				
			}
				
			else if (dama1[i][j] == -1 && (dama1[i+1][j+1] != 0 && dama1[i+1][j-1] != 0)){
			
				peda3[l][0] = i;
				peda3[l][1] = j;
				
				l++;
				
			}
				
			else if (dama1[i][j] == -1 && (dama1[i+1][j+1] == 0 || dama1[i+1][j-1] == 0)){
			
				peda2[m][0] = i;
				peda2[m][1] = j;
		
				m++;
				
			}
		
		}

	}
	
	printf("\nVocê tem %d pedras que podem capturar brancas.\n", qnt1);
	printf("Você tem %d pedras que podem se mover livrementes\n", qnt2);
	printf("Você tem %d pedras que não podem se mover\n\n", qnt3);
	
	printf("Considerar posições: linhas i (de 0 a 7) & colunas j (de 0 a 7)\n\n");
	
	
	if (qnt1 != 0){
		
		printf("As posições das pedras que podem capturar outras são: \n\n");
	
		for (i=0; i<qnt1; i++){
		
			printf("posição: i = %d\tj = %d\n", peda1[i][0]-1, peda1[i][1]-1);
		
		}
		
		printf("\n");
	
	}
	
	if (qnt2 != 0){
		
		printf("As posições das pedras que podem se mover livremente são: \n\n");
	
		for (i=0; i<qnt2; i++){
		
			printf("posição: i = %d\t\tj = %d\n", peda2[i][0]-1, peda2[i][1]-1);
		
		}
		
		printf("\n");
	
	}
	
	if (qnt3 != 0){
		
		printf("As posições das pedras que não podem se mover são: \n\n");
	
		for (i=0; i<qnt3; i++){
		
			printf("posição: i = %d\t\tj = %d\n", peda3[i][0]-1, peda3[i][1]-1);
		
		}
		
		printf("\n");
	
	}
	
}


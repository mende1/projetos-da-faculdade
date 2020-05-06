#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	int num, i, cp, dif, p, y;
	
	printf("Digite o valor máximo de tentativas: ");
	scanf("%d", &y);
	
	#define MAX y //Definição do número máximo de palpites que o computador poderá dar.
	
	int min, max;
	
	printf("Digite o valor mínimo do intervalo: ");
	scanf("%d", &min);
	
	printf("Digite o valor máximo do intervalo: ");
	scanf("%d", &max);
	
	/*Definição do número mínimo e máximo do intervalo que o computador poderá 
	dar seus paltites e que o usuário poderá digitar o número a ser procurado.*/
	
	srand(time(NULL));
	
	printf("Irei tentar advinhar o número que você digitar.\n");
	printf("Digite um número (de %d a %d): ", min, max);
	scanf("%d", &num);
	
	//Número que o usuário quer que o computador "advinhe" de acordo com o intervalo que o mesmo escolheu.
	
	while(num < min || num > max){
	
		printf("Número inválido, tente novamente!\n\n");
		
		printf("Digite um número (de %d a %d): ", min, max);
		scanf("%d", &num);
	
	} 
	
	/* Mecanismo para garantir que o usuário digite um número válido dentro do intervalo definido por ele.
	 O programa irá repetir essa entrada até que o usuário digite um número válido */
	
	for (i=0; i<MAX; i++){
	
		dif = (max - min);
	
		cp = rand() % (dif+1);
		
		p = cp + min;
		
		printf("O número sorteado foi %d.\n", p);
		
		//Mecanismo de sorteio de números de acordo com o limite pré-definido pelo usuário.

		
		if (p < num)
			
			min = p + 1;
				
		else if (p == num)
			
			break;
				
		else
				
			max = p - 1;
			
		/*Simulação de perguntas feitas ao usuário se o palpite é maior ou menor do que o número procurado;
		~Se a chave p for menor que o número procurado, o computador irá aumentar o limite mínimo de seus palpites;
		~Se a chave p for maior que o número procurado, o computador irá diminuir o limite máximo de seus palpites;
		~Se a chave p for igual ao número procurado, irá sair do loop, e concluir o programa.*/
			
	}
		
	if (p == num)
			
		printf("~ACERTEI !!\n > Encontrei seu número na %dª tentativa.\n", i+1);
			
	else
	
		printf("~NÃO ACHEI!\n > Esgotei meu número máximo de tentativas (%d vezes).\n", MAX);
			
	//Conclusão do programa que irá dizer se o computador conseguiu achar o número procurado ou não.

	return 0;

}

/*É possível notar a diferença explícita do programa ao adicionar o algoritmo de simulação de perguntas ao usuário,
se o palpite da máquina é maior ou menor do que o número procurado, é explícito que a quantidade de tentativas diminiu drasticamente,
em relação ao mesmo programa sem este algoritmo, o mesmo que em situações de intervalos grandes demais, tinha dificuldade de achar
a chave procurada, problema esse que foi resulvida após a implementação do algoritmo de Simulação de perguntas ao usuário.*/


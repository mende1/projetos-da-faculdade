#include <stdio.h>

int main(){
	
	enum boolean {
		true = 1, false = 0	};
	
	typedef enum boolean bool;
	
	int n, i, j;
	
	printf("Deseja ver os números primos de 1 até quanto? ");
	scanf("%d", &n);

	bool peneira[n+1];
	
	for (i=0; i<=n; i++)
	
		peneira[i] = true;
	
	peneira[0] = false;
	peneira[1] = false;
	
	for (i=2; i<=n; i++){
	
		if (peneira[i] == true){
		
			for (j=i+1; j<=n; j++){
			
				if (j % i == 0)
				
					peneira[j] = false;
			
			}
		
		}
	
	}
	
	printf("Os números primos entre (0 e %d) são:\n", n);
	
	for (i=1; i<=n; i++){
	
		if (peneira[i] == true){
			
			printf("%d, ", i);

		}
	
	}
	
	printf("\b\b.\n");

}


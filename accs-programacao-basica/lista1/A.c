#include <stdio.h>

int main() {
	int esp, temp;

	scanf("%d %d", &esp, &temp);

	int vel = esp / temp;

	printf("%d\n", vel);
}
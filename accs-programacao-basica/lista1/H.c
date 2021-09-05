#include <stdio.h>

int main() {

	int num;

	scanf("%d", &num);

	int cent = num / 100;
	int deze = (num - cent*100) / 10;
	int unid = num - deze*10 - cent*100;

	printf("%d %d %d\n", unid, deze, cent);
}
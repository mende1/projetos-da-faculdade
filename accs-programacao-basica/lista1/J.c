#include <stdio.h>

int main() {

	int seg;

	scanf("%d", &seg);

	int hora = seg / 3600;

	int minutos = (seg - hora * 3600) / 60;

	seg -= hora * 3600 + minutos * 60;

	printf("%dh %dm %ds\n", hora, minutos, seg);
}
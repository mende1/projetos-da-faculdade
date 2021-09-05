#include <stdio.h>

int main() {

	int tam, dist;

	scanf("%d %d", &tam, &dist);

	int p_km, p_ped;

	scanf("%d %d", &p_km, &p_ped);

	int peds = tam / dist;

	int ans = (tam * p_km) + (peds * p_ped);

	printf("%d\n", ans);
}
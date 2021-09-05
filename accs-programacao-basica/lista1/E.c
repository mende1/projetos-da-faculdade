#include <stdio.h>

int main() {

	int x, y, raio;

	scanf("%d %d %d", &x, &y, &raio);

	int max_x = x / (2 * raio);
	int max_y = y / (2 * raio);

	int ans = max_x * max_y;

	printf("%d\n", ans);
}
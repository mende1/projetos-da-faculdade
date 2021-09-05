#include <stdio.h>

int main() {

	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	int ans = a + b + c + d - 8;

	printf("%d\n", ans);
}
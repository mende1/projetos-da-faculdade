#include <stdio.h>

int main() {

	int t, x;

	scanf("%d %d", &t, &x);

	int ans = x % t;

	printf("%d\n", ans);
}
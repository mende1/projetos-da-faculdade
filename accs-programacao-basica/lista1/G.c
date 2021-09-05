#include <stdio.h>

int main() {

	int q1, q2, q3;
	int e1, e2, e3;

	scanf("%d %d %d", &q1, &q2, &q3);

	int total = q1 + q2 + q3;

	scanf("%d %d %d", &e1, &e2, &e3);

	int p_total = 3 * (e1 + e2 + e3);

	int ans = total - p_total;

	printf("%d\n", ans);
}
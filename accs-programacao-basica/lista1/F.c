#include <stdio.h>

int main() {

	long long a1, a2, a3, a4, a5;

	scanf("%lld %lld %lld %lld %lld", &a1, &a2, &a3, &a4, &a5);

	long long ans = a1 + a2 + a3 + a4 + a5;

	printf("%lld\n", ans);
}
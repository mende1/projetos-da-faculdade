#include <stdio.h>

int main() {

    int lm, vv, cv, n;

    scanf("%d", &n);

    lm = n / 3;
    vv = (n - lm) / 2;
    cv = (n - lm - vv);

    printf("Chapeuzinho Vermelho %d\n", cv);
    printf("Vovozinha %d\n", vv);
    printf("Lobo Mau %d\n", lm);
}
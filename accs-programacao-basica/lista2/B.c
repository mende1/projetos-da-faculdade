#include <stdio.h>

int main() {

    int L = 0;
    int P = 0;

    int Lo, Po;

    scanf("%d %d", &Lo, &Po);

    L += Lo;
    P += Po;

    scanf("%d %d", &Lo, &Po);

    L += Lo;
    P += Po;

    scanf("%d %d", &Lo, &Po);

    L += Lo;
    P += Po;

    if (L > P) {
        printf("Lucas\n");
    }
    else if (P > L) {
        printf("Pedro\n");
    }
    else {
        printf("Empate\n");
    }
}
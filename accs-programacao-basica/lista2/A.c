#include <stdio.h>

int main() {

    int a1, a2;
    int b1, b2;

    scanf("%d %d", &a1, &a2);
    scanf("%d %d", &b1, &b2);

    if (a1 == b1 && a2 == b2) {
        printf("Soltar pacote\n");
    }
    else {
        printf("Nao soltar pacote\n");
    }

}
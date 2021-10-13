#include <stdio.h>

int main() {

    int n, q;

    scanf("%d %d", &n, &q);

    if ((q - n) % 2 == 0 && q >= n) {
        printf("vendido\n");
    }
    else {
        printf("sinto muito\n");
    }
}
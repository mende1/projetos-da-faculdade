#include <stdio.h>

int main() {

    int C, c, x;

    scanf("%d %d %d", &C, &c, &x);

    int a = C / c;

    if (a * a * a > x) {
        printf("!Eh possivel\n");
    }
    else {
        printf("Eh possivel\n");
    }
}
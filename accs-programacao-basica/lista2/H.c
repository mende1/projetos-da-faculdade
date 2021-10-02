#include <stdio.h>

int main() {

    char z, g;
    char d, c;

    scanf("%s %s", &z, &g);
    scanf("%s %s", &d, &c);

    if (z == d) {
        printf("Driblado\n");

        if (g == c) {
            printf("Gol\n");
        }
        else {
            printf("...e o goleiro pega\n");
        }
    }
    else {
        printf("Bloqueado\n");
    }
}
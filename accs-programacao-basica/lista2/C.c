#include <stdio.h>

int main() {

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    c++;

    if ((a * b) >= c) {
        printf("S\n");
    }
    else {
        printf("N\n");
    }
}
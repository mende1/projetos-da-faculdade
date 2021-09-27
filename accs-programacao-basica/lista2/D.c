#include <stdio.h>

int main() {

    int tr, i, tn;

    scanf("%d %d %d\n", &tr, &i, &tn);

    if (tn == 2) {
        printf("VITORIA\n");
    }
    else {
        printf("%d %d %d\n", 9 - tr, 3 - i, 2 - tn);
    }
}
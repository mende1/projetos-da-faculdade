#include <stdio.h>

int main() {

    int c, o, l, x;

    scanf("%d %d %d %d", &c, &o, &l, &x);

    int C = c / 4;
    int O = o / 8;
    int L = l / 2;
    int X = x / 1;

    int min = C;

    if (O < min) {
        min = O;
    }
    if (L < min) {
        min = L;
    }
    if (X < min ) {
        min = X;
    }

    int seg = min * 1259;

    int hora = seg / 3600;

    seg -= hora * 3600;

    int minuto = seg / 60;

    seg -= minuto * 60;

    printf("%d h %d m %d s\n", hora, minuto, seg);
}
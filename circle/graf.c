#include <stdio.h>
#include "ga.h"

int main(void) {
    double start, step, end;
    Ponto a, b, c;
    Circle o;
    Reta r;

    //printf("Insira dois pontos no formato \"X Y\"\n");
    scanf("%lf%lf", &a.x, &a.y);
    scanf("%lf%lf", &b.x, &b.y);

    //printf("Insira uma equação da reta no fomato \"m k\"\n");
    scanf("%lf%lf", &r.m, &r.k);

    //printf("Insira um início, um passo e um final desejado\n");
    //scanf("%lf%lf%lf", &start, &step, &end);

    start = 0.1;
    step = 0.5;
    end = 10;

    for(double x = start; x < end; x += step) {
        c = novoPonto(r, x);
        o = novaCircunferencia(a, b, c);
        printf("(%.2lf, %.2lf) - %lf\n", o.centro.x, o.centro.y, o.raio);
    }

    return 0;
}
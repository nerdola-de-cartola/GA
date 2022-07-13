#include <stdio.h>
#include "ga.h"

int main(void) {
    Ponto a, b, c;
    Circle o;

    printf("Escreva três pontos no formato: \"X Y\"\n");
    scanf("%lf%lf", &a.x, &a.y);
    scanf("%lf%lf", &b.x, &b.y);
    scanf("%lf%lf", &c.x, &c.y);

    o = novaCircunferencia(a, b, c);

    printf("Centro: (%.2lf, %.2lf)\n", o.centro.x, o.centro.y);
    printf("Raio: %.2lf\n", o.raio);
    printf("Equação: (X-%.2lf)^2 + (Y-%.2lf)^2 = %.2lf^2\n", o.centro.x, o.centro.y, o.raio);

    return 0;
}

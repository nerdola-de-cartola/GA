#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Ponto;

typedef struct {
    double m;
    double k;
} Reta;

typedef struct {
    Ponto centro;
    double raio;
} Circle;


Ponto diferenca(Ponto a, Ponto b);
double distancia(Ponto a, Ponto b);
double modulo(Ponto a);
Ponto pontoMedio(Ponto a, Ponto b);
double produtoEscalar(Ponto a, Ponto b);
Reta retaPerpendicular(Reta r, Ponto a);
Reta novaReta(Ponto a, Ponto b);
Ponto interseccao(Reta r, Reta s);


int main(void) {
    Ponto a, b, c;
    Ponto medio_ab, medio_ac;
    Reta r, s;
    Reta perpendicular_r, perpendicular_s;
    Circle o;

    printf("Escreva três pontos no formato: \"X Y\"\n");
    scanf("%lf%lf", &a.x, &a.y);
    scanf("%lf%lf", &b.x, &b.y);
    scanf("%lf%lf", &c.x, &c.y);

    medio_ab = pontoMedio(a, b);
    medio_ac = pontoMedio(a, c);

    r = novaReta(a, b);
    s = novaReta(a, c);

    perpendicular_r = retaPerpendicular(r, medio_ab);
    perpendicular_s = retaPerpendicular(s, medio_ac);
    
    o.centro = interseccao(perpendicular_r, perpendicular_s);
    o.raio = distancia(o.centro, a);

    printf("Centro: (%.2lf, %.2lf)\n", o.centro.x, o.centro.y);
    printf("Raio: %.2lf\n", o.raio);
    printf("Equação: (X-%.2lf)^2 + (Y-%.2lf)^2 = %.2lf^2\n", o.centro.x, o.centro.y, o.raio);

    return 0;
}

Ponto diferenca(Ponto a, Ponto b) {
    Ponto c;

    c.x = b.x - a.x;
    c.y = b.y - a.y;

    return c;
}

double distancia(Ponto a, Ponto b) {
    return  modulo(diferenca(a, b));
}

double modulo(Ponto a) {
    return sqrt((a.x*a.x) + (a.y*a.y));
}

Ponto pontoMedio(Ponto a, Ponto b) {
    Ponto c;

    c.x = (a.x+b.x)/2;
    c.y = (a.y+b.y)/2;

    return c;
}

double produtoEscalar(Ponto a, Ponto b) {
    return (a.x*b.x) + (a.y*b.y);
}

Reta retaPerpendicular(Reta r, Ponto a) {
    Reta p; 

    p.m = -1/r.m;
    p.k = a.y - (p.m*a.x);

    return p;
}

Reta novaReta(Ponto a, Ponto b) {
    Reta r;

    r.m = (a.y-b.y) / (a.x-b.x);
    r.k = a.y - (r.m*a.x);

    return r;
}

Ponto interseccao(Reta r, Reta s) {
    Ponto a;

    a.x = (s.k - r.k) / (r.m - s.m);
    a.y = (r.m*a.x) + r.k;

    return a;
}
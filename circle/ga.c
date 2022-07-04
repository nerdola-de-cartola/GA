#include "ga.h"

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

    if(r.m == 0) {
        printf("ERRO - RETA COM COEFICIENTE IGUAL A ZERO\n");
        exit(1);
    }

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

Circle novaCircunferencia(Ponto a, Ponto b, Ponto c) {
    Reta mediatriz_a_b, mediatriz_a_c;
    Circle o;

    mediatriz_a_b = retaPerpendicular(novaReta(a, b), pontoMedio(a, b));
    mediatriz_a_c = retaPerpendicular(novaReta(a, c), pontoMedio(a, c));
    
    o.centro = interseccao(mediatriz_a_b, mediatriz_a_c);
    o.raio = distancia(o.centro, a);

    return o;
}

Ponto novoPonto(Reta r, double x) {
    Ponto p;

    p.x = x;
    p.y = (r.m * p.x) + r.k;

    return p;
}
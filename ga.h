#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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

Circle novaCircunferencia(Ponto a, Ponto b, Ponto c);

Ponto novoPonto(Reta r, double x);
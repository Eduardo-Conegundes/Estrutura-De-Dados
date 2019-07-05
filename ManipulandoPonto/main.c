#include <stdlib.h>
#include <stdio.h>
#include "Ponto.c"

int main(void){
    float distancia, x, y;
    float *x1 = &x, *y1 = &y;
    Ponto *p, *q;

    p = pto_cria(10, 21);
    q = pto_cria(7, 25);
    
    distancia = pto_distancia(p, q);
    pto_acessa(p, x1, y1);

    printf("\n\n Distancia entre os pontos p e q: %.2f", distancia);
    printf("\n\n Recuperando ponto p, x = %.2f, y = %.2f", x, y);

    pto_atribui(q, x, y);

    printf("\n\n Recuperando ponto q (depois da atribuicao do ponto p no ponto q), x = %.2f, y = %.2f \n\n\n", q->x, q->y);

    pto_libera(q);
    pto_libera(p);
    
    return 0;
}
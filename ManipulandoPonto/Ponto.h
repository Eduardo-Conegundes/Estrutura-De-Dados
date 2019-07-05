struct ponto{
    float x;
    float y;
};

typedef struct ponto Ponto;

// Cria um novo ponto
Ponto* pto_cria(float x, float y);

// Libera um ponto
void pto_libera(Ponto* p);

// Acessa os valores "x" e "y" de um ponto
void pto_acessa(Ponto* p, float* x, float* y);

// Atribui os valores "x" e "y" a um ponto
void pto_atribui(Ponto* p, float x, float y);

// Calcula a distância entre dois pontos
float pto_distancia(Ponto* p1, Ponto* p2);


// Aloca e retorna um ponto com coordenadas "x" e "y"
Ponto* pto_cria(float x, float y){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));

    if(p != NULL){
        p->x = x;
        p->y = y;
    }

    return p;
}

// Libera a memória alocada para um ponto
void pto_libera(Ponto* p){
    free(p);
}

// Recupera, por referência, o valor de um ponto
void pto_acessa(Ponto* p, float* x, float* y){
    *x = p->x;
    *y = p->y;
}

// Atribui a um ponto as coordenadas "x" e "y"
void pto_atribui(Ponto* p, float x, float y){
    p->x = x;
    p->y = y;
}

// Calcula a distância entre dois pontos
float pto_distancia(Ponto* p1, Ponto* p2){
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    
    return sqrt(dx * dx + dy * dy);
}

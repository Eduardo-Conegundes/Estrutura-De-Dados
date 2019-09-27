#ifndef LISTA_DIN_ENCAD_CIRCULAR
#define LISTA_DIN_ENCAD_CIRCULAR

typedef struct aluno{
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
}T_aluno;

typedef struct elemento *Lista;

Lista* cria_lista();

void libera_lista(Lista *li);

int tamanho_lista(Lista *li);

#endif

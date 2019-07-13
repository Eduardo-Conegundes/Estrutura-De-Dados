#ifndef LISTADINENCAD
#define LISTADINENCAD

typedef struct aluno{
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
}T_aluno;

typedef struct elemento* Lista;

int MenuDeOpcoes(void);

Lista* cria_lista();

void libera_lista(Lista* li);

#endif
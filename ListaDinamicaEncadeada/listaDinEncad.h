#ifndef LISTADINENCAD
#define LISTADINENCAD

typedef struct aluno{
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
}T_aluno;

typedef struct elemento* Lista;

int MenuDeOpcoes();

void cadastar_alunos(Lista* li);

void mostrar_todos_alunos(Lista* li);

Lista* cria_lista();

void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int lista_vazia(Lista* li);

int insere_lista_inicio(Lista* li, T_aluno aluno);

int insere_lista_final(Lista* li, T_aluno aluno);

int insere_lista_ordenada(Lista* li, T_aluno aluno);

int remove_lista_inicio(Lista* li);

int remove_lista_final(Lista* li);

int remove_lista(Lista* li, int matricula_aluno);

#endif
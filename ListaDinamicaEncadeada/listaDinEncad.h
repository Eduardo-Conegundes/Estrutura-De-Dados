#ifndef LISTA_DIN_ENCAD
#define LISTA_DIN_ENCAD

typedef struct aluno{
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
}T_aluno;

typedef struct elemento{
    T_aluno dados;
    struct elemento *prox;
}T_elem;

typedef T_elem *Lista;

void MenuDeOpcoes(int* opcao);

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

int remove_lista(Lista* li, int matricula);

int busca_lista_posicao(Lista* li, int posicao);

int busca_lista_matricula(Lista* li, int matricula);

#endif
#ifndef LISTASEQUENCIAL_H
#define LISTASEQUENCIAL_H

#define MAX 100

// Estrutura para dados dos alunos
struct aluno {
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
};

struct aluno Aluno;
typedef struct lista Lista;

// Cria uma lista com dois campos qtd(quantidade) e um vetor do tipo aluno
Lista* cria_lista();

// Libera o espaço de memoria alocado
void libera_lista(Lista* li);

// Retorna o tamnho da lista (quantos elementos já foram inseridos)
int tamanho_lista(Lista* li);

// Verifica se a lista está cheia (li->qtd == MAX)
int lista_cheia(Lista* li);

// Verifica se a lista está vazia (li->qtd == 0)
int lista_vazia(Lista* li);

// Insere os dados no final da lista
int insere_lista_final(Lista* li, struct aluno al);

// Insere os dados no inicio da lista
int insere_lista_inicio(Lista* li, struct aluno al);

// insere os dados em uma lista ordenada
int insere_lista_ordenada(Lista* li, struct aluno al);

// Cadastro os dados do aluno
struct aluno cadastro_de_alunos(struct aluno al);

// Menu de opcoes para escolha das funções disponiveis
int MenuDeOpcoes(void);

#endif
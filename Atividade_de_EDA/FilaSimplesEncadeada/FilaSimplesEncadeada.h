#ifndef Fila_Simples_Encadeada
#define Fila_Simples_Encadeada

typedef struct noDescritorDaFila{
    struct no *inicio;
    struct no *final;
}T_NoDescritor;

typedef struct no{
    int dado;
    struct no *proximo;
}T_FilaSimples;

T_NoDescritor* criaFila(void);

void MenuDeOpcoes(int *opcao);

int destruirFila(T_NoDescritor *Fila);

int FilaVazia(T_NoDescritor *Fila);

void mostraValoresDaFila(T_NoDescritor *Fila);

void removeFila(T_NoDescritor *Fila);

void insereValor(T_NoDescritor *Fila, int valor);

#endif
#ifndef Fila_Simples_Encadeada
#define Fila_Simples_Encadeada

// Estrutura para facilitar a remoção e inserção na fila.
// Já que são manipulado apenas o primeiro e ultimo elemento da fila.
// Guarda o primeiro elemento da fila e o ultimo elemento da fila.
typedef struct noDescritorDaFila{
    struct no *inicio;
    struct no *final;
}T_NoDescritor;

typedef struct no{
    int dado;
    struct no *proximo;
}T_FilaSimples;

// Função que cria a fila (fazendo com que a cabeça da fila aponte para null)
// Retorna um ponteiro do tipo "T_NoDescritor".
T_NoDescritor* criaFila(void);

// Menu de opção para manipulação da fila.
void MenuDeOpcoes(int *opcao);

// Libera todos os "no"s da fila, assim destruindo a fila
// Retorna a quantidade de "no"s removido/destruidos/liberados.
int destruirFila(T_NoDescritor *Fila);

// Função que verifica se a fila está vazia
// Ou seja a cabeça da fila (inicio) aponta pra NULL.
int FilaVazia(T_NoDescritor *Fila);

// Função que mostra os valores da Fila.
void mostraValoresDaFila(T_NoDescritor *Fila);

// Remove um valor da fila, especificamente o primeiro elemento da fila (SEMPRE).
void removeFila(T_NoDescritor *Fila);

// Insere um valor na fila, especificamente no final da fila (SEMPRE).
void insereValor(T_NoDescritor *Fila, int valor);

#endif
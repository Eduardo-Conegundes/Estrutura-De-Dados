#ifndef Pilha_Simples_Encadeada
#define Pilha_Simples_Encadeada

typedef struct no{
    int dado;
    struct no *proximo;
}T_PilhaSimples;

// Função que cria a pilha, retorna um ponteiro do tipo T_PilhaSimples.
T_PilhaSimples* criaPilha(void);
// Função do menu de opções, recebe um ponteiro q vai receber o número da opção escolhida
// cdomo é um ponteiro não precisa retornar.
void MenuDeOpcoes(int *opcao);
// Função que deleta a pilha, deletando primeiramente cada "no" depois deleta a "cabeça" da pilha.
int destruirPilha(T_PilhaSimples **pilha);
// Função que verifica se a pilha está vazia, ou seja o primeiro elemento é NULL.
int pilhaVazia(T_PilhaSimples **pilha);
// Função que printa na tela os valores da pilha.
void mostraValoresDaPilha(T_PilhaSimples **pilha);
// Função que remove um valor da pilha, sempre remove o valore que está mais em cima, ou seja
// o valor que foi colocado por último.
void removePilha(T_PilhaSimples **pilha);
// Função para inserir valores na pilha, recebe a pilha e o valor a ser inserido, e sempre insere
// em cima da pilha.
void insereValor(T_PilhaSimples **pilha, int valor);

#endif
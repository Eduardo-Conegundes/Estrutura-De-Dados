#ifndef Lista_Encadeada_Dupla
#define Lista_Encadeada_Dupla

typedef struct no{
    struct no *anterior; 
    int dado;
    struct no *proximo;
}T_ListaDupla;


//Função que cria a lista (fazendo com que a cabeça da lista aponte para null)
//Retorna um ponteiro para ponteiro
T_ListaDupla* criaLista(void);

//Funcção que mostra o menu de opcoes de ações na lista
//Como o valor é passado por referência não tem retorno
void MenuDeOpcoes(int *opcao);

//Função que verifa se a lista tá vazia, ou seja se a cabeça da lista aponta pra NULL
//Retorn 1 se a lista estiver vazia e 0 se a lista não estiver vazia
int verificaListaVazia(T_ListaDupla **lista);

//Insere um valor na lista, deixando a lista com valores em ordem crescente
void insereValor(T_ListaDupla **lista, int valor);

//Remove um valor na lista, ainda deixando a lista com valores em ordem crescente
void removeValor(T_ListaDupla **lista, int valor);

//Procura por um valor na lista
void procuraValor(T_ListaDupla **lista, int valor);

//Lista todos os valores da lista em orde crescente
void listaValoresOrdemCrescente(T_ListaDupla **lista);

//Lista todos os valores da lista em orde decrescente
void listaValoresOrdemDecrescente(T_ListaDupla **lista);

//Libera todos os "no" da lista, assim destruindo a lista
int destruirLista(T_ListaDupla **lista);

#endif
#include <stdio.h>
#include <stdlib.h>
#include "PilhaSimplesEncadeada.h"

T_PilhaSimples* criaPilha(void){
    // Aloca um espaço de memoria para o tipo "T_PilhaSimples".
    T_PilhaSimples *pilha = (T_PilhaSimples*)malloc(sizeof(T_PilhaSimples));
    // Verifica se foi possivel alocar esse espaço de memoria.
    if(pilha != NULL){
        // Se foi alocado com sucesso, o ponteiro pilha aponta pra NULL, ou seja, a pilha
        // foi criada mas está vazia.
        pilha = NULL;  
    }

    // Retorna o ponteiro do tipo "T_PilhaSimples".
    return pilha;
}

void MenuDeOpcoes(int *opcao){
    printf("\n\n *-*-*-*-* MENU PRINCIPAL -*-*-*-*-* \n\n");

    printf(" Escolha uma opcao: \n\n");
    printf(" 1- Pilha vazia?\n 2- Adicionar valor\n 3- Remover valor");
    printf("\n 4- Pilha valores\n 5- Sair\n\n");

    printf(" Opcao: ");
    // Como "opcao" é um ponteiro, não precisa colocar o "&", o nome "opcao" já é um endereço de memoria.
    scanf("%d", opcao);
}

int destruirPilha(T_PilhaSimples **pilha){
    // Variavel para guardar a quantidade de "no"s q foi desalocados.
    int quantidadeDeNos = 0;

    // Verifica se a pilha está vazia, se não estiver...
    if(!pilhaVazia(pilha)){
        // Cria um ponteiro do tipo "T_PilhaSimples" que inicialmente aponta para NULL.
        T_PilhaSimples *no = NULL;
        // Laço de repetição que vai se repetir até que "*pilha" seja NULL, ou seja chegue no final da lista.
        while(*pilha != NULL){
            // O "no" agora aponta pra "*pilha"
            no = *pilha;
            // E "*pilha" vai para o proximo elemento...
            *pilha = (*pilha)->proximo;
            // Libera o espaço de memoria que "no" está apontando.
            free(no);
            // Aumenta a quantidade de "no"s que foram desalocados em 1.
            // (quantidadedeNos++;) é igual a (quantidadedeNos = quantidadedeNos + 1;).
            quantidadeDeNos++;
        }
        // Depois que todos os "no"s foram desalocados, libera o espaço da cabeça da pilha tbm,
        // assim toda a pilha foi liberada.
        free(pilha);
    }
    // Retorna a quantidade de "no"s liberados/desalocados.
    return quantidadeDeNos;
}

int pilhaVazia(T_PilhaSimples **pilha){
    // Verifica se o primeiro elemento da pilha é NULL, se for é porque a pilha está vazia.
    // retornando 1.
    if(*pilha == NULL){
        return 1;
    }
    
    // Caso a pilha não esteja vazia, retorna 0.
    return 0;
}

void insereValor(T_PilhaSimples **pilha, int valor){
    // Aloca um espaço de memoria para o tipo "T_PilhaSimples".
    T_PilhaSimples *no = (T_PilhaSimples*)malloc(sizeof(T_PilhaSimples));
    // Pega o valor passado que será inserido na pilha e atribui a "no->dado"
    no->dado = valor;
    // Atribui o primeiro elemento da pilha (*pilha) a "no->proximo", ou seja, agora o "no" aponta 
    // para o primeiro elemento da pilha.
    no->proximo = *pilha;
    // E o primeiro elemento da pilha passa a ser o no agora.
    *pilha = no;
}

void removePilha(T_PilhaSimples **pilha){
    // Verifica se a pilha está vazia, se estiver não tem elemento para remover.
    if(pilhaVazia(pilha)){
        printf("\n Pilha vazia\n");
    }else{
        // Cria um ponteiro do tipo "T_PilhaSimples" e faz com que ele aponte para o primeiro elemento da pilha. 
        T_PilhaSimples *no = *pilha;
        // o primeiro elemento da pilha agora aponta para o proximo elemento, fazendo com que esse elemento se torne
        // o primeiro elemento da pilha.
        *pilha = (*pilha)->proximo;
        // Libera o "no" que era o antigo primeiro elemento da pilha.
        free(no);
        printf("\n Valor do topo da pilha removido!\n");
    }
}

void mostraValoresDaPilha(T_PilhaSimples **pilha){
    // Verifica se a pilha está vazia, se estiver não tem elemento para ser mostrado.
    if(pilhaVazia(pilha)){
        printf("\n Pilha vazia\n");
    }else{
        // Cria um ponteiro do tipo "T_PilhaSimples" e faz com que ele aponte para o primeiro elemento da pilha. 
        T_PilhaSimples *no = *pilha;
        // Enquanto no for diferente de NULL, ou seja não chegou no final da pilha...
        while(no != NULL){
            // Printa o valor do "no".
            printf("|%5d     |\n", no->dado);  
            // E vai para o proximo "no".          
            no = no->proximo;
        }
        printf("_ _ _ _ _ _");
    }
}
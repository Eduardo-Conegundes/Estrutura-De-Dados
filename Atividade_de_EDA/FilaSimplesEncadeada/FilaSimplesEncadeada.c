#include <stdio.h>
#include <stdlib.h>
#include "FilaSimplesEncadeada.h"

T_NoDescritor* criaFila(void){
    // Alloca um espaço de memoria, que é um ponteiro para o tipo "T_NoDescritor"
    // Que será o "no" que aponta para o primeiro e ultimo elemento da fila...
    T_NoDescritor *Fila = (T_NoDescritor*)malloc(sizeof(T_NoDescritor));

    // Verifica se a alloção foi feita com sucesso...
    if(Fila != NULL){
        // o inicio e final aponta para NULL indicando que a fila está vazia...
        // Foi criada com sucesso, mas não tem valores inseridos ainda...
        Fila->inicio = NULL;
        Fila->final = NULL;
    }

    // Retorna a fila, criada com sucesso, porem vazia...
    return Fila;
}

void MenuDeOpcoes(int *opcao){
    printf("\n\n *-*-*-*-* MENU PRINCIPAL -*-*-*-*-* \n\n");

    printf(" Escolha uma opcao: \n\n");
    printf(" 1- Fila vazia?\n 2- Adicionar valor\n 3- Remover valor");
    printf("\n 4- Fila valores\n 5- Sair\n\n");

    printf(" Opcao: ");
    // Não precisa do "&" porque "opcao" foi passado por referencia...
    scanf("%d", opcao);
}

int destruirFila(T_NoDescritor *Fila){
    int quantidadeDeNos = 0;

    // Se a fila está vazia, a quantidade de "no"s desalocado/destruido é 0
    if(FilaVazia(Fila)){
        // Desalloca o "no" que quarda o primeiro e ultimo elemento...
        // Assim destruindo a fila por completo.
        free(Fila);
        return quantidadeDeNos;
    }else{
        // Cria um ponteiro para o tipo "T_FilaSimples"
        T_FilaSimples *no;
        // Enquanto o inicio da fila não chegar em NULL ou seja no final da fila, vai para o proximo "no".
        while(Fila->inicio != NULL){
            // "no" é um "no" auxiliar, ajuda para desallocar o espaço de memoria.
            // Aponta para onde o inicio da fila aponta atualmente. 
            no = Fila->inicio;
            // O inicio da fila aponta para o proximo elemento.
            Fila->inicio = Fila->inicio->proximo;
            // Libera o "no".
            free(no); 
            // Aumenta a quantidade de "no"s destruidos...
            quantidadeDeNos++;
        }
        // Desalloca o "no" que quarda o primeiro e ultimo elemento...
        // Assim destruindo a fila por completo.
        free(Fila);
    }

    // Retorna a quantidade de "no"s desallocados/destruido...
    return quantidadeDeNos;
}

int FilaVazia(T_NoDescritor *Fila){
    // Se o inicio da fila aponta para NULL indica que a fila está vazia.
    if(Fila->inicio == NULL){
        return 1;   // True
    }
    return 0;   // False
}

void insereValor(T_NoDescritor *Fila, int valor){
    T_FilaSimples *no = (T_FilaSimples*)malloc(sizeof(T_FilaSimples));
    no->dado = valor;
    no->proximo = NULL;

    // Se a fila está vazia...
    if(Fila->final == NULL){ 
        // O inicio da fila passa a apontar para o "no" que está sendo inserido...
        Fila->inicio = no;
    }else{
        // Caso a fila não esteja vazia o ultimo "no" aponta para o "no" que está sendo inserido...
        Fila->final->proximo = no;
    }
    // O final da fila agora passa a ser o "no" inserido...
    // Lembrando que na fila, é sempre inserido no final.
    Fila->final = no;
}

void removeFila(T_NoDescritor *Fila){
    // Verifca se a fila está vazia.
    if(FilaVazia(Fila)){
        printf("\n Fila vazia\n");
    }else{
        // Cria um ponteiro que aponta para o inicio da fila.
        T_FilaSimples *no = Fila->inicio;
        // O inico da final agora aponta para o proximo elemento.
        // Ou seja o inicio da fila agora é o segundo elemento.
        Fila->inicio = Fila->inicio->proximo;
        // Se o inicio da fila agora tá apontando para NULL indica que a fila ficou vazia.
        // Só tinha um elemento na fila.
        if(Fila->inicio == NULL){
            // O final da fila passa a apontar para NULL.
            Fila->final = NULL;
        }
        // Libera o "no" que foi excluido.
        free(no);
        printf("\n Valor do inicio da fila removido!\n");
    }
}

void mostraValoresDaFila(T_NoDescritor *Fila){
    // Verifca se a fila está vazia.
    if(FilaVazia(Fila)){
        printf("\n Fila vazia\n");
    }else{
        // Cria um ponteiro que aponta para o inicio da fila.
        T_FilaSimples *no = Fila->inicio;
        printf(" inicio -> ");
        // Enquanto "no" for diferente de NULL, ou seja não chegou no final da fila.
        while(no != NULL){
            // Mostra o valor do "no".
            printf("%d ", no->dado); 
            // E vai para o proximo "no".           
            no = no->proximo;
        }
        printf("<- final\n\n");
    }
}
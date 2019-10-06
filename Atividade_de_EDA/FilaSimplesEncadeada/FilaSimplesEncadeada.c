#include <stdio.h>
#include <stdlib.h>
#include "FilaSimplesEncadeada.h"

T_NoDescritor* criaFila(void){
    T_NoDescritor *Fila = (T_NoDescritor*)malloc(sizeof(T_NoDescritor));

    if(Fila != NULL){
        Fila->inicio = NULL;
        Fila->final = NULL;
    }

    return Fila;
}

void MenuDeOpcoes(int *opcao){
    printf("\n\n *-*-*-*-* MENU PRINCIPAL -*-*-*-*-* \n\n");

    printf(" Escolha uma opcao: \n\n");
    printf(" 1- Fila vazia?\n 2- Adicionar valor\n 3- Remover valor");
    printf("\n 4- Fila valores\n 5- Sair\n\n");

    printf(" Opcao: ");
    scanf("%d", opcao);
}

int destruirFila(T_NoDescritor *Fila){
    int quantidadeDeNos = 0;

    if(FilaVazia(Fila)){
        return quantidadeDeNos;
    }else{
        T_FilaSimples *no;
        while(Fila->inicio != NULL){
            no = Fila->inicio;
            Fila->inicio = Fila->inicio->proximo;
            free(no); 
            quantidadeDeNos++;
        }
        free(Fila);
    }

    return quantidadeDeNos;
}

int FilaVazia(T_NoDescritor *Fila){
    if(Fila->inicio == NULL){
        return 1;
    }
    return 0;
}

void insereValor(T_NoDescritor *Fila, int valor){
    T_FilaSimples *no = (T_FilaSimples*)malloc(sizeof(T_FilaSimples));
    no->dado = valor;
    no->proximo = NULL;

    if(Fila->final == NULL){ // A fila está vazia
        Fila->inicio = no;
    }else{
        Fila->final->proximo = no;
    }
    Fila->final = no;
}

void removeFila(T_NoDescritor *Fila){
    if(FilaVazia(Fila)){
        printf("\n Fila vazia\n");
    }else{
       T_FilaSimples *no = Fila->inicio;
       Fila->inicio = Fila->inicio->proximo;
       if(Fila->inicio == NULL){
           Fila->final = NULL;
       }
       free(no);
       printf("\n Valor do inicio da fila removido!\n");
    }
}

void mostraValoresDaFila(T_NoDescritor *Fila){
    if(FilaVazia(Fila)){
        printf("\n Fila vazia\n");
    }else{
        T_FilaSimples *no = Fila->inicio;
        printf(" inicio -> ");
        while(no != NULL){
            printf("%d ", no->dado);            
            no = no->proximo;
        }
        printf("<- final\n\n");
    }
}
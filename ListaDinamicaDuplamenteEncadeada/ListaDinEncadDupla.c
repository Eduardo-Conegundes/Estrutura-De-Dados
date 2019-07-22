#include "ListaDinEncadDupla.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct elemento {
    T_elem *anterior;
    T_aluno *dados;
    T_elem *proximo;
}T_elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL){
        *li = NULL;
    }

    return li;
}

void libera_lista(Lista* li){
    
    if(li != NULL){
        T_elem* no;
        
        while((*li) != NULL){
            no = *li;
            *li = (*li)->proximo;
            free(no);
        }

        free(li);
    }
}

void MenuDeOpcoes(int* opcao){
    
    printf("\n\n *-*-*-*-* MENU PRINCIPAL -*-*-*-*-* \n\n");

    printf(" Escolha uma opcao: \n\n");
    printf(" 1- Cadastrar alunos\n 2- Mostra alunos cadastrados\n 3- Remover aluno");
    printf("\n 4- Buscar por aluno\n 5- Tamanho da lista\n 6- A lista esta vazia?\n 7- Sair\n\n");

    printf(" Opcao: ");
    scanf("%d", opcao);
}
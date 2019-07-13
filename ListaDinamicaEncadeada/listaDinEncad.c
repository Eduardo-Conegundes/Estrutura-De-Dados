#include "listaDinEncad.h"
#include <stdlib.h>

typedef struct elemento{
    struct aluno dados;
    struct elemento* prox;
}T_elem;

int MenuDeOpcoes(void){
    int op;

    printf("\n\n *-*-*-*-* MENU PRINCIPAL -*-*-*-*-* \n\n");

    printf(" Escolha uma opcao: \n\n");
    printf(" 7- Sair\n");

    printf(" Opcao: ");
    scanf("%d", &op);

    return op;
}

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
            *li = (*li)->prox;
            free(no);
        }

        free(li);
    }
}
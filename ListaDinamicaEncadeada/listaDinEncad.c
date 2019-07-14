#include "listaDinEncad.h"
#include <stdlib.h>

typedef struct elemento{
    struct aluno dados;
    struct elemento* prox;
}T_elem;

int MenuDeOpcoes(){
    int op;

    printf("\n\n *-*-*-*-* MENU PRINCIPAL -*-*-*-*-* \n\n");

    printf(" Escolha uma opcao: \n\n");
    printf(" 5- Tamanho da lista\n 6- A lista esta vazia?\n 7- Sair\n\n");

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

int tamanho_lista(Lista* li){
    system("cls");
    
    if(li == NULL){
        return -1;
    }else{
        int cont = 0;
        T_elem* no = *li;   

        while(no != NULL){
            cont++;
            no = no->prox;
        }

        return cont;
    }
}

int lista_vazia(Lista* li){
    system("cls");

    if(li == NULL){
        return -1;
    }else if( (*li) == NULL ){
        return 1;
    }else{
        return 0;
    }
}
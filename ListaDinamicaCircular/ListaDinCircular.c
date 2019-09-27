#include "ListaDinCircular.h";

typedef struct elemento{
    T_aluno dados;
    struct elemento *proximo;
}T_elem;


Lista* cria_lista(){
    Lista *li = (Lista*)malloc(sizeof(Lista));

    if(li != NULL){
        li = NULL;
    }

    return li;
}

void libera_lista(Lista *li){
    if(li != NULL && *li != NULL){ 
        T_elem *no = *li, *aux;         

        while(*li != no->proximo){
            aux = no;
            no = no->proximo;
            free(aux);
        }

        free(no);
        free(li);
    }
}
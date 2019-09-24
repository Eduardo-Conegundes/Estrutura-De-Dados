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
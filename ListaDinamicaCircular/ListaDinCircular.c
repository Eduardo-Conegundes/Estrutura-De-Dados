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

int tamanho_lista(Lista *li){
    int tamanho = 0;

    if(li == NULL){
        return -1;
    }else if(*li == NULL){
        return 0;
    }
     
    T_elem *no = *li;
    do{
        tamanho++;
        no = no->proximo;
    }while(*li != no);

    return tamanho;
}

int lista_vazia(Lista *li){
    if(li == NULL){
        return -1;
    }

    if(*li == NULL){
        return 1; // True
    }else{
        return 0; // False
    }
}

int insere_inicio_lista(Lista *li, T_aluno al){
    if(li == NULL){
        return  -1;
    }

    T_elem *no = (T_elem*)malloc(sizeof(T_elem));
    no->dados = al;

    if(*li == NULL){
        no->proximo = no;
        *li = no;
    }else{
        T_elem *aux = *li;
        
        while(aux->proximo != *li){
            aux = aux->proximo;
        }

        aux->proximo = no;
        no->proximo = *li;
        *li = no;
    }

    return 1;
}
#include "ListaDinEncadDupla.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct elemento {
    T_elem *anterior;
    T_aluno dados;
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

int tamanho_lista(Lista* li){
    system("cls");
    
    if(li == NULL){
        return -1;
    }else{
        int cont = 0;
        T_elem* no = *li;   

        while(no != NULL){
            cont++;
            no = no->proximo;
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

int insere_lista_inicio(Lista* li, T_aluno aluno){
    system("cls");

    if(li == NULL){
        return -1;
    }else{
        T_elem* no = (T_elem*) malloc(sizeof(T_elem));

        no->anterior = NULL;
        no->dados = aluno;
        no->proximo = (*li);
        
        // Verifica se a lista está vazia

        if((*li) != NULL){ // Se não estiver vazia...
            (*li)->anterior = no;
        }

        *li = no;

        return 1;
    }

}

int insere_lista_final(Lista* li, T_aluno aluno){

    if(li == NULL){
        return -1;
    }else{
        T_elem* no = (T_elem*) malloc(sizeof(T_elem));

        no->dados = aluno;
        no->proximo= NULL;

        if((*li) == NULL){
            no->anterior = NULL;
            *li = no;
        }else{
            T_elem* aux = *li;
            
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }

            aux->proximo = no;
            no->anterior = aux;
        }

        return 1;
    }
}

void cadastar_alunos(Lista* li){
    system("cls");
    T_aluno aluno;
    char opcao;

    do{
        printf("\n Matricula do aluno: ");
        scanf("%i", &aluno.matricula);

        printf("\n Nome do aluno: ");
        scanf("%s", aluno.nome);

        printf("\n Primeira nota do aluno: ");
        scanf("%f", &aluno.nota1);

        printf("\n Segunda nota do aluno: ");
        scanf("%f", &aluno.nota2);

        printf("\n Segunda nota do aluno: ");
        scanf("%f", &aluno.nota3);
        
        //insere_lista_inicio(li, aluno);
        //insere_lista_final(li, aluno);
        insere_lista_ordenada(li, aluno);

        system("cls");
        printf("\n\n Deseja cadastar outro aluno? [s/n]: ");
        scanf(" %c", &opcao);

    }while(opcao != 'n');

}

int insere_lista_ordenada(Lista* li, T_aluno aluno){
    
    if(li == NULL){
        return -1;
    }else{
        T_elem* no = (T_elem*) malloc(sizeof(T_elem));

        no->dados = aluno;
        no->proximo = NULL;

        if((*li) == NULL){
            no->anterior = NULL;
            *li = no;
            return 1;
        }else{
            T_elem *anterior, *atual = (*li);

            while(atual != NULL && atual->dados.matricula < no->dados.matricula){
                anterior = atual;
                atual = atual->proximo;
            }
            
            if(atual == (*li)){
                no->anterior = NULL;
                no->proximo = (*li);
                (*li)->anterior = no;
                *li = no;
            }else{
                // Obs: "anterior->proximo" é igual a "atual"
                no->proximo = anterior->proximo; 
                no->anterior = anterior;
                anterior->proximo = no;
                if(atual != NULL){
                    atual->anterior = no;
                }
            }
    
            return 1;
        }
    }
}

void mostrar_todos_alunos(Lista* li){
    system("cls");

    if(li == NULL){
        printf("\n Lista nao existe!!\n\n");
    }else if( (*li) == NULL){
        printf("\n Lista vazia!\n\n");
    }else{
        T_elem* no = (*li);

        while(no != NULL){
            printf("\n Matricula: %i\n", no->dados.matricula);
            printf(" Nome: %s\n", no->dados.nome);
            printf(" Primeira nota: %.1f\n", no->dados.nota1);
            printf(" Segunda nota: %.1f\n", no->dados.nota2);
            printf(" Terceira nota: %.1f\n", no->dados.nota3);
            printf("\n -------------------------------------\n");

            no = no->proximo;
        }
    }
}

int remove_lista_inicio(Lista* li){
    if(li == NULL){
        return -1;
    }

    if(*li == NULL){
        return 0;
    }

    T_elem *no = *li;
    *li = no->proximo;

    if(no->proximo != NULL){
        no->proximo->anterior = NULL;
    }

    free(no);

    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL){
        return -1;
    }

    if(*li == NULL){
        return 0;
    }

    T_elem *no = *li;

    while(no->proximo != NULL){
        no = no->proximo;
    }

    if(no->anterior == NULL){
        *li = no->proximo; // no->proximo ou NULL (são a msm coisa)
    }else{
        no->anterior->proximo = NULL;
    }
    
    free(no);
    
    return 1;
}

int remove_lista(Lista* li, int matricula){
    if(li == NULL){
        return -1;
    }
    
    T_elem *no = *li;

    while(no != NULL && no->dados.matricula != matricula){
        no = no->proximo;
    }

    if(no == NULL){  // Não achou
        return 0;
    }

    if(no->anterior == NULL){
        *li = no->proximo;
    }else{
        no->anterior->proximo = no->proximo;
    }

    if(no->proximo != NULL){
        no->proximo->anterior = no->anterior;
    }

    free(no);

    return 1;
}
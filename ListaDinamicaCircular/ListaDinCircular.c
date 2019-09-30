#include <stdlib.h>
#include <stdio.h>
#include "ListaDinCircular.h";

Lista* cria_lista(){
    Lista *li = (Lista*)malloc(sizeof(Lista));

    if(li != NULL){
        li = NULL;
    }

    return li;
}

void MenuDeOpcoes(int* opcao){
    printf("\n\n *-*-*-*-* MENU PRINCIPAL -*-*-*-*-* \n\n");

    printf(" Escolha uma opcao: \n\n");
    printf(" 1- Cadastrar alunos\n 2- Mostra alunos cadastrados\n 3- Remover aluno");
    printf("\n 4- Buscar por aluno\n 5- Tamanho da lista\n 6- A lista esta vazia?\n 7- Sair\n\n");

    printf(" Opcao: ");
    scanf("%d", opcao);
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

void mostrar_todos_alunos(Lista* li){
    system("cls");

    if(li == NULL){
        printf("\n Lista nao existe!!\n\n");
    }else if( (*li) == NULL){
        printf("\n Lista vazia!\n\n");
    }else{
        T_elem* no = (*li);
        do{
            printf("\n Matricula: %i\n", no->dados.matricula);
            printf(" Nome: %s\n", no->dados.nome);
            printf(" Primeira nota: %.1f\n", no->dados.nota1);
            printf(" Segunda nota: %.1f\n", no->dados.nota2);
            printf(" Terceira nota: %.1f\n", no->dados.nota3);
            printf("\n -------------------------------------\n");
            no = no->proximo;
        }while(no != *li);
    }
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
    }else if(*li == NULL){
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

int insere_final_lista(Lista *li, T_aluno al){
    if(li == NULL){
        return -1;
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
    }

    return 1;
}

int insere_lista_ordenada(Lista *li, T_aluno al){
    if(li == NULL){
        return -1;
    }

    T_elem *no = (T_elem*)malloc(sizeof(T_elem));
    no->dados = al;

    if(*li == NULL){
        no->proximo = no;
        *li = no;
    }else{
        if((*li)->dados.matricula > al.matricula){
            T_elem *aux = *li;

            while(aux->proximo != *li){
                aux = aux->proximo;
            }

            aux->proximo = no;
            no->proximo = *li;
            *li = no;
        }else{
            T_elem *anterior = *li, *atual = (*li)->proximo;

            while(atual != *li && atual->dados.matricula < al.matricula){
                anterior = atual;
                atual = atual->proximo;
            }

            anterior->proximo = no;
            no->proximo = atual;
        }
    }

    return 1;
}

int remove_lista_inicio(Lista *li){
    if(li == NULL){
        return -1;
    }else if(*li == NULL){
        return 0;
    }else{

        if(*li == (*li)->proximo){
            free(*li);
            *li = NULL;
            return 1;
        }

        T_elem *aux = *li, *no = *li;

        while(aux->proximo != *li){
            aux = aux->proximo;
        }

        *li = (*li)->proximo;
        aux->proximo = *li;

        free(no);   

        return 1;
    }
}

int remove_lista_final(Lista *li){
    if(li == NULL){
        return -1;
    }else if(*li == NULL){
        return 0;
    }else{
        if(*li = (*li)->proximo){
            free(*li);
            *li = NULL;
        }

        T_elem *anterior = NULL, *no = *li;

        while(no->proximo != *li){
            anterior = no;
            no = no->proximo;
        }
        anterior->proximo = *li;
        free(no);
        return 1;
    }
}

int remove_lista(Lista *li, T_aluno al){
    if(li == NULL){
        return -1;
    }else if(*li == NULL){
        return 0;
    }else{
        if((*li)->dados.matricula == al.matricula){
            if(*li == (*li)->proximo){
                free(*li);
                *li = NULL;
                return 1;
            }else{
                T_elem *aux = *li, *no = *li;
                while(aux->proximo != *li){
                    aux = aux->proximo;
                }
                *li = (*li)->proximo;
                aux->proximo = *li;
                free(no);
                return 1;
            }
        }

        T_elem *anterior = *li, *no = (*li)->proximo;

        while(no != *li && no->dados.matricula != al.matricula){
            anterior = no;
            no = no->proximo;
        }

        if(no == *li){
            return 0;
        }else{
            anterior->proximo = no->proximo;
            free(no);
            return 1;
        }
    }
}

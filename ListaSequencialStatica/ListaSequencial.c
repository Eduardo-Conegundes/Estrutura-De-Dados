#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaSequencial.h"

// li = lista
// al = aluno
// qtd = quantidade de alunos cadastrados

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista(){
    Lista *li;

    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
    }

    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int tamanho_lista(Lista* li){
    system("cls");
    
    if(li == NULL){
        return -1;
    }else{
        return li->qtd;
    }
}

int lista_cheia(Lista* li){
    system("cls");

    if(li == NULL){
        return -1;
    }else{
        return (li->qtd == MAX);
    }
}

int lista_vazia(Lista* li){
    system("cls");

    if(li == NULL){
        return -1;
    }else{
        return (li->qtd == 0);
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    system("cls");

    if(li == NULL){
        return -1;
    }else if(lista_cheia(li)){
        return 0;
    }else{
        li->dados[li->qtd] = al;
        li->qtd++;
        return 1;
    }
}

int insere_lista_inicio(Lista* li, struct aluno al){
    system("cls");

    if(li == NULL){
        return -1;
    }else if(lista_cheia(li)){
        return 0;
    }else{
        int i;
        for(i = li->qtd; i > 0; i--){
            li->dados[i] = li->dados[i-1];
        }
        li->dados[i] = al; // i = 0
        li->qtd++;
        return 1;
    }
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    system("cls");

    if(li == NULL){
        return -1;
    }else if(lista_cheia(li)){
        return 0; 
    }else{
        int k, i = 0;

        while(i < li->qtd && li->dados[i].matricula < al.matricula){
            i++;
        }

        for(k = li->qtd; k > i; k--){
            li->dados[k] = li->dados[k-1];
        }

        li->dados[i] = al;
        li->qtd++;

        return 1;
    }
}

struct aluno cadastro_de_alunos(struct aluno al){
    system("cls");

    printf("\n Digite a sua matricula: ");
    scanf("%d", &al.matricula);

    printf("\n Digite a seu nome: ");
    scanf(" %s", al.nome);

    printf("\n Digite a sua primeira nota: ");
    scanf("%f", &al.nota1);

    printf("\n Digite a sua segunda nota: ");
    scanf("%f", &al.nota2);

    printf("\n Digite a sua terceira nota: ");
    scanf("%f", &al.nota3);

    system("cls");

    return al;
}

int MenuDeOpcoes(void){
    int op;

    printf("\n\n *-*-*-*-* MENU PRINCIPAL -*-*-*-*-* \n\n");

    printf(" Escolha uma opcao: \n\n");
    printf(" 1- Cadastrar alunos\n 2- Verificar tamanho da lista\n 3- Verificar se a lista esta cheia\n");
    printf(" 4- Verificar se a lista esta vazia\n 5- Remover\n 6- Consultar\n 7- Sair\n\n");

    printf(" Opcao: ");
    scanf("%d", &op);

    return op;
}

int remove_lista_final(Lista* li){
    system("cls");

    if(li == NULL){
        return -1;
    }else if(li->qtd == 0){
        return 0;
    }else{
        li->qtd--;
        return 1;
    }
}

int remove_lista_inicio(Lista* li){
    system("cls");

    if(li == NULL){
        return -1;
    }else if(li->qtd == 0){
        return 0;
    }else{
        int i;

        for(i = 0; i < li->qtd - 1; i++){
            li->dados[i] = li->dados[i+2];
        }

        li->qtd--;

        return 1;
    }
}

int remove_lista(Lista* li, int matricula){
    system("cls");

    if(li == NULL){
        return -1;
    }else if(li->qtd == 0){
        return 0;
    }else{
        int i = 0, k;

        while(i < li->qtd && li->dados[i].matricula != matricula) i++;

        if(i == li->qtd){   // Não encontrado
            return 0;
        }else{

            for(k = i; k < li->qtd - 1; k++){
                li->dados[k] = li->dados[k+1];
            }
            li->qtd--;
            return 1;
        }
    }

}

int consulta_lista_pos(Lista* li, int pos, struct aluno* dados_aluno){
    if(li == NULL || pos <= 0 || pos > li->qtd){
        return 0;
    }else{
        *dados_aluno = li->dados[pos-1];
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int matricula, struct aluno* dados_aluno){
    if(li == NULL || matricula < 0){
        return 0;
    }else{
        int i = 0;

        while(i < li->qtd && li->dados[i].matricula != matricula) i++;

        if(i == li->qtd){
            return 0;
        }else{
            *dados_aluno = li->dados[i];
            return 1;
        }
    }
}

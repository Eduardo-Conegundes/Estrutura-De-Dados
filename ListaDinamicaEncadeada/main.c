#include <stdio.h>
#include "listaDinEncad.c"

int main (void){
    system("cls");

    int opcao = 0, x, matricula;
    Lista* li;

    li = cria_lista();

    do{
        MenuDeOpcoes(&opcao);

        switch(opcao){
            case 1:
                cadastar_alunos(li);
            break;

            case 2:
                mostrar_todos_alunos(li);
            break;
                
            case 3:
                system("cls");
                printf("\n Informe a matricula do aluno: ");
                scanf("%d", &matricula);

                x = remove_lista(li, matricula);

                if(x == -1){
                    printf("\n\n Lista inexistente!\n\n");
                }else if(x == 1){
                    printf("\n\n Aluno removido com sucesso!\n\n");
                }else{
                    printf("\n Aluno nao encontrado!\n\n");
                }
            break;
                
            case 4:
                system("cls");
                printf("\n Informe a matricula do aluno: ");
                scanf("%d", &matricula);

                x = busca_lista_matricula(li, matricula);;

                if(x == -1){
                    printf("\n\n Lista inexistente!\n\n");
                }else if(x == 0){
                    printf("\n Aluno nao encontrado!\n\n");
                }
                
            break;
                
            case 5:
                if(tamanho_lista(li) == -1){
                    printf("\n Lista inexistente!\n\n");
                }else{
                    printf("\n Tamanho da lista: %d\n\n", tamanho_lista(li));
                }
            break;

            case 6:
                x = lista_vazia(li);

                if(x == -1){
                    printf("\n Lista inexistente!\n\n");                    
                }else if(x == 1){
                    printf("\n Sim, Lista vazia!\n\n");
                }else{
                    printf("\n Nao, a lista nao esta vazia\n\n");
                }

            break;
            case 7:
                printf("\n Saindo...\n\n");
            break;

            default:
                system("cls");
                printf("\n Opcao invalida!\n\n");
            break;
        }
    }while(opcao != 7);

    libera_lista(li);

    return 0;
}
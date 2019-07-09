#include "ListaSequencial.c"

int main(void){
    char resposta = 's';
    int i, opcoes;
    Lista *li;

    li = cria_lista();

    do{

        opcoes = MenuDeOpcoes();

        switch (opcoes){
            case 1:
                do{
                    Aluno = cadastro_de_alunos(Aluno);

                    if(insere_lista_final(li, Aluno)){
                        printf("\n Dados inseridos com sucesso\n");
                    }else{
                        printf("\n Erro ao inserir dados\n");
                    }

                    printf("\n Deseja inserir outro aluno? (s/n): ");
                    scanf(" %c", &resposta);
                }while(resposta == 's' && i < MAX);
            break;

            case 2:
                printf("\n Tamanho da lista: %d\n", tamanho_lista(li));
            break;

            case 3:
                if(lista_cheia(li)){
                    printf("\n A lista esta cheia!\n");
                }else{
                    printf("\n A lista nao esta cheia!\n");
                }
            break;

            case 4:
                if(lista_vazia(li)){
                    printf("\n A lista esta vazia!\n");
                }else{
                    printf("\n A lista nao esta vazia!\n");
                }
            break;
            case 5:
                int cpf;
                
                printf("\n Digite seu cpf: ");
                scanf("%d", &cpf);

                if(remove_lista(li, cpf)){
                    printf("\n Removido com sucessor\n\n");
                }else{
                    printf("\n Errro ao remover da lista\n\n");
                }
            break;
            case 6:
                system("cls");
                printf("\n Finalizado!\n\n");
            break;
            default:
                printf("\n Opcao invalida!\n\n");
            break;
        }
    }while(opcoes != 6);
    
    libera_lista(li);

    return 0;
}

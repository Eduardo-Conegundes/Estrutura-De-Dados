#include "ListaSequencial.c"

int main(void){
    char resposta = 's';
    int i, opcoes;
    int matricula;
    struct aluno dados_aluno;
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
                printf("\n Digite sua matricula: ");
                scanf("%d", &matricula);
            
                if(remove_lista(li, matricula)){
                    printf("\n Removido com sucessor\n\n");
                }else{
                    printf("\n Errro ao remover da lista\n\n");
                }
            break;

            case 6:
                printf("\n Digite seu matricula: ");
                scanf("%d", &matricula);

                if(consulta_lista_mat(li, matricula, &dados_aluno)){
                    printf("\n\n Matricula: %d", dados_aluno.matricula);
                    printf("\n Nome: %s", dados_aluno.nome);
                    printf("\n Nota1: %.2f Nota2: %.2f Nota3: %.2f\n",
                    dados_aluno.nota1, dados_aluno.nota2,dados_aluno.nota3);
                }else{
                    printf("\n Matricula nao encontrada!\n\n");
                }
            break;

            case 7:
                system("cls");
                libera_lista(li);
                printf("\n Finalizado!\n\n");
            break;

            default:
                printf("\n Opcao invalida!\n\n");
            break;
        }
    }while(opcoes != 7);
    
    libera_lista(li);

    return 0;
}

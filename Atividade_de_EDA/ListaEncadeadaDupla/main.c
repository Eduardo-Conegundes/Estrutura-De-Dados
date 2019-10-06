#include "ListaEncadeadaDupla.c"

int main(void){
    // Cria um ponteiro do tipo "T_ListaDupla" e chama a função "criaLista" q retorna um ponteiro
    // que aponta pra NULL assim criando uma lista inicialmente vazia.
    T_ListaDupla *lista =  criaLista();
    // Variavel "opcoes" para guardar o valor escolhido do menu de opções.
    // Variavel "valor" para guardar o valor que será guardado na lista.
    int opcoes, valor;

    do{
        MenuDeOpcoes(&opcoes);
        switch(opcoes){
            case 1:
                system("cls");
                if(verificaListaVazia(&lista)){
                    printf("\n A lista esta vazia!\n");
                }else{
                    printf("\n A lista nao esta vazia!\n");
                }
            break;

            case 2:
                system("cls");
                printf("\n Valor: ");
                scanf("%d", &valor);
                insereValor(&lista, valor);
            break;
            
            case 3:
                system("cls");
                printf("\n Valor: ");
                scanf("%d", &valor);
                removeValor(&lista, valor);
            break;

            case 4:
                system("cls");
                printf("\n Valor: ");
                scanf("%d", &valor);
                procuraValor(&lista, valor);
            break;

            case 5:
                system("cls");
                listaValoresOrdemCrescente(&lista);
            break;

            case 6:
                system("cls");
                listaValoresOrdemDecrescente(&lista);
            break;
            
            case 7:
                system("cls");
                printf("\n Saindo....\n");
                printf(" Quantidade de 'no' liberados = %d\n\n", destruirLista(&lista));
            break;
            default:
                system("cls");
                printf("Opcao invalida!");
            break;
        }

    }while(opcoes != 7);

    return 0;
}
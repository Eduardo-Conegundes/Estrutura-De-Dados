#include "PilhaSimplesEncadeada.c"

int main(void){
    // Cria um ponteiro do tipo "T_PilhaSimples" e chama a função "criaPilha" q retorna um ponteiro
    // que aponta pra NULL assim criando uma Pilha inicialmente vazia.
    T_PilhaSimples *pilha =  criaPilha();
    // Variavel "opcoes" para guardar o valor escolhido do menu de opções.
    // Variavel "valor" para guardar o valor que será guardado na pilha.
    int opcoes, valor;

    do{
        MenuDeOpcoes(&opcoes);
        switch(opcoes){
            case 1:
                system("cls");
                if(pilhaVazia(&pilha)){
                    printf("\n A pilha esta vazia!\n");
                }else{
                    printf("\n A pilha nao esta vazia!\n");
                }
            break;

            case 2:
                system("cls");
                printf("\n Valor: ");
                scanf("%d", &valor);
                insereValor(&pilha, valor);
            break;
            
            case 3:
                system("cls");
                removePilha(&pilha);
            break;

            case 4:
                system("cls");
                mostraValoresDaPilha(&pilha);
            break;

            case 5:
                system("cls");
                printf("\n Saindo....\n");
                printf(" Quantidade de 'no' liberados = %d\n\n", destruirPilha(&pilha));
            break;
            default:
                system("cls");
                printf("Opcao invalida!");
            break;
        }

    }while(opcoes != 5);

    return 0;
}
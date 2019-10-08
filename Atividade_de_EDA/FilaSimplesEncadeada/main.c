#include "FilaSimplesEncadeada.c"

int main(void){
    // Cria um ponteiro do tipo "T_NoDescritor" e chama a função "criaFila" q retorna um ponteiro
    // que aponta pra NULL assim criando uma fila inicialmente vazia.
    T_NoDescritor *Fila =  criaFila();
    // Variavel "opcoes" para guardar o valor escolhido do menu de opções.
    // Variavel "valor" para guardar o valor que será guardado na fila.
    int opcoes, valor;

    do{
        MenuDeOpcoes(&opcoes);
        switch(opcoes){
            case 1:
                system("cls");
                if(FilaVazia(Fila)){
                    printf("\n A Fila esta vazia!\n");
                }else{
                    printf("\n A Fila nao esta vazia!\n");
                }
            break;

            case 2:
                system("cls");
                printf("\n Valor: ");
                scanf("%d", &valor);
                insereValor(Fila, valor);
            break;
            
            case 3:
                system("cls");
                removeFila(Fila);
            break;

            case 4:
                system("cls");
                mostraValoresDaFila(Fila);
            break;

            case 5:
                system("cls");
                printf("\n Saindo....\n");
                printf(" Quantidade de 'no' liberados = %d\n\n", destruirFila(Fila));
            break;
            default:
                system("cls");
                printf("Opcao invalida!");
            break;
        }

    }while(opcoes != 5);

    return 0;
}
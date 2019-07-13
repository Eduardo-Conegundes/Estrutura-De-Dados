#include "listaDinEncad.c"

int main (void){
    int opcao;
    Lista* li;

    li = cria_lista();

    do{
        opcao = MenuDeOpcoes();

        switch(opcao){
            case 1:
                // CODE
            break;

            case 2:
                // CODE
            break;
                
            case 3: 
                // CODE
            break;
                
            case 4:
                // CODE
            break;
                
            case 5:
                // CODE
            break;

            case 6:
                // CODE
            break;
            case 7:
                printf("\n Saindo...\n\n");
            break;

            default:
                printf("\n Opcao invalida!\n\n");
            break;
        }
    }while(opcao != 7);

    libera_lista(li);

    return 0;
}
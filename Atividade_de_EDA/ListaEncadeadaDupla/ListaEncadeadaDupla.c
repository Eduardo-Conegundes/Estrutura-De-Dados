#include <stdio.h>   
#include <stdlib.h>
#include "ListaEncadeadaDupla.h"

T_ListaDupla* criaLista(void){
    // Aloca um espaço de memoria para o tipo "T_ListaDupla".
    T_ListaDupla *lista = (T_ListaDupla*)malloc(sizeof(T_ListaDupla));
    // Verifica se foi possivel alocar esse espaço de memoria.
    if(lista != NULL){
        // Se foi alocado com sucesso, o ponteiro lista aponta pra NULL, ou seja, a lista
        // foi criada mas está vazia.
        lista = NULL;
    }else{
        printf("\n Erro ao criar lista\n");
        // Sai da função sem retornar nada.
        return;
    }
    // Retorna o ponteiro do tipo "T_ListaDupla".
    return lista;
}

void MenuDeOpcoes(int *opcao){
    
    printf("\n\n *-*-*-*-* MENU PRINCIPAL -*-*-*-*-* \n\n");

    printf(" Escolha uma opcao: \n\n");
    printf(" 1- Lista vazia?\n 2- Adicionar valor\n 3- Remover valor");
    printf("\n 4- Buscar por valor\n 5- Lista valor (Crescente)\n 6- Lista valor (Decrescente)\n 7- Sair\n\n");

    printf(" Opcao: ");
    // Como "opcao" é um ponteiro, não precisa colocar o "&", o nome "opcao" já é um endereço de memoria.
    scanf("%d", opcao);
}

int verificaListaVazia(T_ListaDupla **lista){
    // Verifica se o primeiro elemento da lista é NULL, se for NULL é porque a lista está vazia.
    // retornando 1.
    if(*lista == NULL){  
        return 1;
    }

    // Caso a lista não esteja vazia, retorna 0.
    return 0;    
}

void insereValor(T_ListaDupla **lista, int valor){
    // Aloca um espaço de memoria para o tipo "T_ListaDupla".
    T_ListaDupla *no = (T_ListaDupla*)malloc(sizeof(T_ListaDupla));
    // Pega o valor passado que será inserido na lista e atribui a "no->dado"
    no->dado = valor;

    // Verifica se a lista está vazia, se estiver o "no" será inserido no inicio da lista
    if(verificaListaVazia(lista)){
        // Então o no->anterior e o no->proximo apontam pra NULL
        no->anterior = NULL;
        no->proximo = NULL;
         // E o primeiro elemento da lista agoar é o "no" (*lista = no;)
        *lista = no;
    }else{ // Caso a lista não esteja vazia.

        // Cria um ponteiro do tipo "T_ListaDupla" e faz com que ele aponte para o primeiro elemento da pilha.
        // Cria um ponteiro do tipo "T_ListaDupla" e faz com que ele aponte para (*anterior = NULL).
        T_ListaDupla *auxiliar = *lista, *anterior = NULL;
        // Laço de repetição que vai executar enquanto o a "auxiliar" for diferente de NULL, ou seja, não chegou 
        // no final da lista e o valor desse "no" auxiliar (auxiliar->dado) 
        // for menor do que o valor passado para a função para ser alocado (inserido na lista)  
        while(auxiliar != NULL && auxiliar->dado < valor){
            // anterior recebe o "no" atual, para que o auxiliar vá para o proximo "no"
            // assim o ponteiro "anterior" sempre aponta para o "no" anteior de "auxiliar" que seria o "no" atual.
            anterior = auxiliar; 
            // O "no" atual ou "auxialiar" vai para o proximo "no".
            auxiliar = auxiliar->proximo;
        }
        // Depois que sai do laço de repetição, verifica se "auxiliar" é igual a "*lista"
        // se for verdade, indica que não entrou nenhuma vez no laço de repetição, ou seja o valor será inserido 
        // no inicio da lista.
        if(auxiliar == *lista){
            // Como vai ser inserido no inicio, o no->anterior aponta para NULL.
            no->anterior = NULL;
            // O no->proximo aponta para o primeiro elemento da lista.
            no->proximo = *lista;
            // O primeiro elemento da lista, agora aponta para o "no", (o ponteiro anterior).
            (*lista)->anterior = no;
            // O primeiro elemento da lista agora é o "no".
            *lista = no; 
        }else{ // Caso o laço de repetição tenha rodado pelo menos uma vez, ou seja o "no" não será inserido no inicio.
            
            // OBS: "auxiliar" é igual a "anterior->proximo"
            // no->proximo aponta pra o anterior->proximo(auxiliar) que é o "no" que vai ficar a frente do "no" que será inserido.
            no->proximo = anterior->proximo;
            // O "no" anterior->proximo aponta agora para o "no" que será inserido.
            anterior->proximo = no;
            // E o "no" que será inserido (no->anterior) ponta para o "no" anterior.
            // Assim o no é enserido no meio do "no" anterior e o "no" anterior->proximo(auxiliar).
            no->anterior = anterior;

            // Se o "no" auxiliar não for igual a NULL, indica que o "no" inserido não é o ultimo.
            // Então o "no" que está a frente do "no" que será inserido deve apontar pra ele também.
            if(auxiliar != NULL){         
                auxiliar->anterior = no;
            }
        }  
    }

}

void removeValor(T_ListaDupla **lista, int valor){
    // Verifica se a lista está vazia, se estiver não tem valor para ser removido.
    if(verificaListaVazia(lista)){
        printf("\n Valor nao encontrado!\n");
    }else{
        // Cria um ponteiro que aponta para o primeiro "no" da lista.
        T_ListaDupla *no = *lista;

        // Procura por o "no" que tem o valor igual o valor passado na função.
        // Enquanto o "no" não chegar no final, ou seja apontar pra NULL, o "no" aponta para o proximo elemento da lista
        // Ou enquanto não achar o valor...
        while(no != NULL && no->dado != valor){
            no = no->proximo;
        }

        // Se "no" for igual a NULL indica que chego no final da lista e não encontrou o valor desejado.
        if(no == NULL){
            printf("\n Valor nao encontrado!\n");
        }else{ // Caso o valor seja encontrado.

            // Verifica se é o primeiro elemento da lista
            // Caso esse no->anterior apontar para NULL indica que ele é o primeiro elemento da lista.
            if(no->anterior == NULL){
                // Então agora o primeiro elemento da lista vai ser o proximo "no".
                *lista = no->proximo;
            }else{ // Caso não seja o primeiro elemento da lista...
                // Essa atribuição faz com que o "no->anterior" deixe de apontar para o "no" que será 
                // removido e passe a apontar para o proximo "no".
                no->anterior->proximo = no->proximo;
            }

            // Verifica se o "no" que será removido é o ultimo elemento, se o "no->proximo" apontar pra NULL
            // Indica que esse "no" é o ultimo elemento, caso contrario, o proximo elemento deve apontar para o no anterior.
            if(no->proximo != NULL){
                no->proximo->anterior = no->anterior;
            }

            system("cls");
            printf("\n Valor removido!");
            // Libera o espaço de memoria do "no" removido da lista.
            free(no);
        }
    }
}

void procuraValor(T_ListaDupla **lista, int valor){
    // Verifica se a lista está vazia, se estiver não tem valor para ser procurado.
    if(verificaListaVazia(lista)){
        printf("\n Valor nao encontrado\n");
    }else{
        // Cria um ponteiro que aponta para o primeiro "no" da lista.
        T_ListaDupla *no = *lista;
        // Enquanto o "no" não chegar no final da lista ou o valor do "no" for encontrado
        while(no != NULL && no->dado != valor){
            no = no->proximo;
        }

        // Se o "no" for igual a NULL é porque o valor não foi encontrado...
        if(no == NULL){
            printf("\n Valor nao encontrado\n");
        }else{ // Caso o valor tenha sido encontrado...
            printf("\n Valor encontrado\n");
        }
    }
}

void listaValoresOrdemCrescente(T_ListaDupla **lista){
    // Verifica se a lista está vazia, se estiver não tem valores para serem printados na tela.
    if(verificaListaVazia(lista)){
        printf("\n Lista vazia\n");
    }else{
        // Cria um ponteiro que aponta para o primeiro "no" da lista.
        T_ListaDupla *no = *lista;
        printf("\n -> ");
        // Enquanto o "no->proximo" não apontar para NULL é porque não chegou no final da lista.
        while(no != NULL){
            // Mostra o valor do "no".
            printf("%d ", no->dado);
            // E "no" aponta para o proximo "no".
            no = no->proximo;
        }
    }
}

void listaValoresOrdemDecrescente(T_ListaDupla **lista){
    // Verifica se a lista está vazia, se estiver não tem valores para serem printados na tela.
    if(verificaListaVazia(lista)){
        printf("\n Lista vazia\n");
    }else{
        // Cria um ponteiro que aponta para o primeiro "no" da lista.
        T_ListaDupla *no = *lista;
        
        // Enquanto o "no->proximo" não apontar para NULL é porque não chegou no final da lista.
        // Laço criado para achar o ultimo elemento da lista, para poder exibir os valores de trás pra frente da lista.
        while(no->proximo != NULL){
            no = no->proximo;
        }
        // Nesta parte do código o "no" é o ultimo "no" da lista...
        printf("\n -> ");
        // Enquanto "no" não apontar para NULL, que neste caso indica que chegou no inicio da lista....
        while(no != NULL){
            // Mostra o valor do "no".
            printf("%d ", no->dado);
            // E aponta para o no->anterior, como queremos andar na lista de trás pra frente.
            no = no->anterior;
        }
    }
}

int destruirLista(T_ListaDupla **lista){
    int quantidadeDeNos = 0;
    // Verifica se a lista está vazia, se estiver retornar 0 ou seja, não tem "no"s na lista.
    if(verificaListaVazia(lista)){
        // Libera a lista...
        free(lista);
        return quantidadeDeNos;
    }else{ // Caso a lista não esteja vazia....

        // Cria um ponteiro para o tipo "T_ListaDupla" e inicialmente ele aponta para NULL.
        T_ListaDupla *no = NULL;
        // Enquanto *lista não for igual a NULL, ou seja o primeiro elemento ou a "cabeça da lista" não chegou no final da lista.
        while(*lista != NULL){
            // Adiciona o "no" que irá ser liberado ao ponteiro "no". 
            no = *lista;
            // Vai para o proximo "no".
            *lista = (*lista)->proximo;
            // Libera o "no".
            free(no);
            // Aumenta a quantidade de "no"s removidos a varialvel "quantidadeDeNos".
            // (quantidadeDeNos++;) é igaul a (quantidadeDeNos = quantidadeDeNos + 1;)
            quantidadeDeNos++;
        }
        // Libera a lista...
        free(lista);
        // Retorna a quantidade de "no"s removidos.
        return quantidadeDeNos;
    }
}
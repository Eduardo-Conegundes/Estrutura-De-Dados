#include "Ordenacao.c"

int main(void){
    int *array = (int *)calloc(1, sizeof(int));
    int arraySize, i = 0, numberOfInteractions = 0;

    printf("\n How many numbers do you want to sort? ");
    scanf("%d", &arraySize);

    printf("\n Enter numbers to be sorted!\n");

    do{
        printf(" >> ");
        scanf("%d", &array[i]);
        // Aloca mais uma posição de memoria...
        array = (int *)realloc(array,  (i+2) * sizeof(int));
        i++;
    }while(i < arraySize);

    printf("\n Array not sorted: ");
    printArrray(array, arraySize);   // Função que "printa" o verto, nesse momento desordenardo;

    // Função QuickSort pra ordenar o vetor 
    QuickSort(array, 0, arraySize, &numberOfInteractions);

    // Mostra as informações
    printf("\n Array sorted: ");
    printArrray(array, arraySize); // Função que "printa" o verto, nesse momento ordenardo;
    printf("\n Array size: %d", arraySize);
    printf("\n number of interactions: %d\n", numberOfInteractions);

    printf("\n\n");
    return 0;
}
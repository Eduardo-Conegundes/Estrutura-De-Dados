#include "Ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int array[], int size){
    int i, x, aux, numberOfInteractions = 0;
    int isSorted = 1;

    while(isSorted){
        isSorted = 0;
        for(i = 0; i < size-1; i++){
            if(array[i] > array[i + 1]){
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                isSorted = 1;
                printArrray(array, size);
            }
        }
        numberOfInteractions++;
    }

    printf("\n Array size: %d", size);
    printf("\n number of interactions: %d\n", numberOfInteractions);
}

void printArrray(int array[], int size){
    int i;
    
    printf("\n");

    for(i = 0; i < size; i++){
        if(i != size - 1){
            printf(" %d, ", array[i]);
        }else{
            printf(" %d ", array[i]);
        }
    }

    printf("\n");;
}




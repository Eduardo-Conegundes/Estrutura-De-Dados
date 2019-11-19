#include "Ordenacao.h"
#include <stdio.h>

void BubbleSort(int array[], int size){
    int i, x, aux;

    for(i = 0; i < size; i++){
        for(x = i + 1; x < size; x++){
            if(array[i] > array[x]){
                aux = array[i];
                array[i] = array[x];
                array[x] = aux;
            }
        }
    }
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

    printf("\n\n");;
}




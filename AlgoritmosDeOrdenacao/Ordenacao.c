#include "Ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int array[], int size){
    int i, x, aux, numberOfInteractions = 0;
    int isSorted = 0;

    while(!isSorted){
        isSorted = 1;
        for(i = 0; i < size-1; i++){
            if(array[i] > array[i + 1]){
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                // Se entrar aqui significa q talvez o vetor ainda não esteja ordenado
                // Então a varial isSorted passa a ser "1" para que o while não pare
                isSorted = 0;  
            }
        }
        numberOfInteractions++; // Contra o número de interações necessarias para ordenar o array
    }

    // Mostra as informações
    printf("\n Array size: %d", size);
    printf("\n number of interactions: %d\n", numberOfInteractions);
}

void printArrray(int array[], int size){
    int i;
    
    printf("\n");

    for(i = 0; i < size; i++){
        if(i != size - 1){
            printf(" %d, ", array[i]); // Entra nesse if se não for o último número do vetor
        }else{
            printf(" %d ", array[i]);  // Entra nesse if se for o último número do vetor
        }
    }

    printf("\n");;
}




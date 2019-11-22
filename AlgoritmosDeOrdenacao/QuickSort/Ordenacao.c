#include "Ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

void QuickSort(int array[], int left, int right, int *numberOfInteractions){
    int pivot, auxiliary;
    int i, x;

    // Se a variavel left for menor do q right 
    if(left < right){
        pivot = i = left; 
        x = right;

        while(i < x){
            //Percorre o vetor até que o valor do array seja maior do que o valor do pivo
            while(array[i] <= array[pivot]&&i<right)i++;
            //Percorre o vetor até que o valor do array seja menor ou igual do que o valor do pivo
            while(array[x] > array[pivot])x--;

            // Se o valor de i for menos do que x, os valores trocam de lugar com a ajuda da variavel auxiliar
            if(i < x){
                auxiliary = array[i];
                array[i] = array[x];
                array[x] = auxiliary;
            }
        }

        // Coloca o valor do pivo no seu devido lugar
        auxiliary = array[pivot];
        array[pivot] = array[x];
        array[x] = auxiliary;

        // Chama a funçao QuickSort recursivamente, passando o sub-vetor do lado esquerdo do pivo
        QuickSort(array, left, x-1, numberOfInteractions);
        // Chama a funçao QuickSort recursivamente, passando o sub-vetor do lado direito do pivo
        QuickSort(array, x+1, right, numberOfInteractions);

        // Variavel (ponteiro) que conta o número de interações
        (*numberOfInteractions)++;
    }

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




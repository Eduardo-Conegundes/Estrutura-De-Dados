#include "Ordenacao.c"

int main(void){
    int array[] = {5, 10, 8, 6, 50, 36, 44, 18, 26, 30, 11, 0, 33, 17, 20};
    int size = sizeof(array)/sizeof(int);

    printArrray(array, size);

    BubbleSort(array, size);
    
    printArrray(array, size);
    
    return 0;
}
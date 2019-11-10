#include "ArvoreBinariaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

BinaryTree* createBinaryTree(){
    BinaryTree *Root = (BinaryTree *)malloc(sizeof(BinaryTree));

    if(Root != NULL){
        *Root = NULL;
    }

    return Root;
}

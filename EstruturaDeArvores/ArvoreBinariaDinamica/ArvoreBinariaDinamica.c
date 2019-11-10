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

void freeTree(BinaryTree *Root){
    if(Root != NULL){
        freeNodes(*Root);
        free(Root);
    }
}

void freeNodes(BinaryTree Node){
    if(Node != NULL){
        freeNodes(Node->Left);
        freeNodes(Node->Right);
        free(Node);
        Node = NULL;
    }
}

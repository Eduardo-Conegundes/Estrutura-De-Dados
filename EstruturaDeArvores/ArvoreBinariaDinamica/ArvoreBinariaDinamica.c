#include "ArvoreBinariaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

enum Types{False, True, NotExist = -1};

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

int isEmpty(BinaryTree *Root){
    if(Root == NULL){
        return NotExist;
    }else if(*Root == NULL){
        return True;
    }else{
        return False;
    }
}

int treeHeight(BinaryTree *Root){
    if(Root == NULL || *Root == NULL){
        return 0;
    }else{
        int leftHeight = treeHeight(&((*Root)->Left));
        int rightHeight = treeHeight(&((*Root)->Right));

        if(leftHeight > rightHeight){
            return leftHeight + 1;
        }else{
            return rightHeight + 1;
        }
    }
}

int totalNodes(BinaryTree *Root){
    if(Root == NULL || *Root == NULL){
        return 0;
    }else{
        int leftHeight = treeHeight(&((*Root)->Left));
        int rightHeight = treeHeight(&((*Root)->Right));

        return (leftHeight + rightHeight + 1);
    }
}

void inorder(BinaryTree *Root){
    if(Root != NULL && (*Root) != NULL){
        preorder(&((*Root)->Left));
        printf("\n Value = %d\n", (*Root)->Value);
        preorder(&((*Root)->Right));
    }
};

void preorder(BinaryTree *Root){
    if(Root != NULL && (*Root) != NULL){
        printf("\n Value = %d\n", (*Root)->Value);
        preorder(&((*Root)->Left));
        preorder(&((*Root)->Right));
    }
};
 
void postorder(BinaryTree *Root){
    if(Root != NULL && (*Root) != NULL){
        preorder(&((*Root)->Left));
        preorder(&((*Root)->Right));
        printf("\n Value = %d\n", (*Root)->Value);
    }
};




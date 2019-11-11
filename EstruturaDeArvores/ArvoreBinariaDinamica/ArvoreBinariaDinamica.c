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
        inorder(&((*Root)->Left));
        printf("\n Value = %d\n", (*Root)->Value);
        inorder(&((*Root)->Right));
    }
}

void preorder(BinaryTree *Root){
    if(Root != NULL && (*Root) != NULL){
        printf("\n Value = %d\n", (*Root)->Value);
        preorder(&((*Root)->Left));
        preorder(&((*Root)->Right));
    }
}
 
void postorder(BinaryTree *Root){
    if(Root != NULL && (*Root) != NULL){
        postorder(&((*Root)->Left));
        postorder(&((*Root)->Right));
        printf("\n Value = %d\n", (*Root)->Value);
    }
}

void insertInTree(BinaryTree *Root, int Value){
    if(Root != NULL){
        /* 
            "BinaryTree" is alread a pointer, that's why it's not required a *,
            otherwise it'd be a pointer to pointer (Double pointer).
        */
        BinaryTree newNode = (BinaryTree) malloc(sizeof(BinaryTree));

        newNode->Value = Value;
        newNode->Left = newNode->Right = NULL;

        if((*Root) == NULL){
            *Root = newNode;
        }else{
            BinaryTree *auxiliaryNode = *Root;

            if((*auxiliaryNode)->Value > Value){ 
                insertInTree(&((*auxiliaryNode)->Left), Value);    
            }else if((*auxiliaryNode)->Value < Value){
                insertInTree(&((*auxiliaryNode)->Right), Value);
            }else{
                printf("\n This number already exists in the tree!\n");
                free(newNode);
            }
        }
    }
}

void removeNode(BinaryTree *Root, int Value){
    if(Root != NULL){
        BinaryTree previousNode = NULL;
        BinaryTree currentNode = *Root;

        while(currentNode != NULL){
            if(currentNode->Value == Value){
                if(currentNode == *Root){
                    *Root = removeSpecificNode(currentNode);
                }else{
                    if(previousNode->Right == currentNode){
                        previousNode->Right = removeSpecificNode(currentNode);
                    }else{
                        previousNode->Left = removeSpecificNode(currentNode);
                    }
                }
                printf("\n Node deleted successfully!\n");
            }

            previousNode = currentNode;

            if(Value > currentNode->Value){
                currentNode = currentNode->Right;
            }else{
                currentNode = currentNode->Left;
            }
        }
    }
}

BinaryTree removeSpecificNode(BinaryTree Node){
    BinaryTree node1, node2;

    // If there's no child or only one child
    if(Node->Left == NULL){
        node2 = Node->Right;
        free(Node);
        return node2;
    }

    node1 = Node;
    node2 = Node->Left;

    while(node2->Right != NULL){
        node1 = node2;
        node2 = node2->Right;
    }

    if(node1 != Node){
        node1->Right = node2->Left;
        node2->Left = Node->Left;
    }

    node2->Right = Node->Right;
    free(Node);
    return node2;
};

void lookForValue(BinaryTree *Root, int Value){
    if(Root != NULL){
        if((*Root == NULL)){
            printf("\n Value not found!\n");
        }else{
            if((*Root)->Value > Value){
                lookForValue(&((*Root)->Left), Value);
            }else if((*Root)->Value < Value){
                lookForValue(&((*Root)->Right), Value);
            }else{
                printf("\n Value found!\n");
            }
        }
    }
}

#include "ArvoreBinariaAVL.h"
#include <stdio.h>
#include <stdlib.h>

enum Types{False, True, NotExist = -1};

AVL_BinaryTree* createBinaryTree(){
    AVL_BinaryTree *Root = (AVL_BinaryTree *)malloc(sizeof(AVL_BinaryTree));

    if(Root != NULL){
        *Root = NULL;
    }

    return Root;
}

void freeTree(AVL_BinaryTree *Root){
    if(Root != NULL){
        freeNodes(*Root);
        free(Root);
    }
}

void freeNodes(AVL_BinaryTree Node){
    if(Node != NULL){
        freeNodes(Node->Left);
        freeNodes(Node->Right);
        free(Node);
        Node = NULL;
    }
}

int isEmpty(AVL_BinaryTree *Root){
    if(Root == NULL){
        return NotExist;
    }else if(*Root == NULL){
        return True;
    }else{
        return False;
    }
}

int treeHeight(AVL_BinaryTree *Root){
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

int totalNodes(AVL_BinaryTree *Root){
    if(Root == NULL || *Root == NULL){
        return 0;
    }else{
        int leftHeight = treeHeight(&((*Root)->Left));
        int rightHeight = treeHeight(&((*Root)->Right));

        return (leftHeight + rightHeight + 1);
    }
}

void inorder(AVL_BinaryTree *Root){
    if(Root != NULL && (*Root) != NULL){
        inorder(&((*Root)->Left));
        printf("\n Value = %d\n", (*Root)->Value);
        inorder(&((*Root)->Right));
    }
}

void preorder(AVL_BinaryTree *Root){
    if(Root != NULL && (*Root) != NULL){
        printf("\n Value = %d\n", (*Root)->Value);
        preorder(&((*Root)->Left));
        preorder(&((*Root)->Right));
    }
}
 
void postorder(AVL_BinaryTree *Root){
    if(Root != NULL && (*Root) != NULL){
        postorder(&((*Root)->Left));
        postorder(&((*Root)->Right));
        printf("\n Value = %d\n", (*Root)->Value);
    }
}

void insertInTree(AVL_BinaryTree *Root, int Value){
    if(Root != NULL){
        /* 
            "AVL_BinaryTree" is alread a pointer, that's why it's not required a *,
            otherwise it'd be a pointer to pointer (Double pointer).
        */
        AVL_BinaryTree newNode = (AVL_BinaryTree) malloc(sizeof(AVL_BinaryTree));

        newNode->Value = Value;
        newNode->Left = newNode->Right = NULL;

        if((*Root) == NULL){
            *Root = newNode;
        }else{
            AVL_BinaryTree *auxiliaryNode = *Root;

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

void removeNode(AVL_BinaryTree *Root, int Value){
    if(Root != NULL){
        AVL_BinaryTree previousNode = NULL;
        AVL_BinaryTree currentNode = *Root;

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

AVL_BinaryTree removeSpecificNode(AVL_BinaryTree Node){
    AVL_BinaryTree node1, node2;

    if(Node->Left == NULL){
        node1 = Node->Right;
    }else if(Node->Right == NULL){
        node1 = Node->Left;
    }else{
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
    }

    free(Node);
    return node1;
};

void lookForValue(AVL_BinaryTree *Root, int Value){
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

int nodeHeight(AVL_BinaryTree Node){
    if(Node == NULL){
        return -1;
    }else{
        return Node->nodeHeight;
    }
}

int balancingFactor(AVL_BinaryTree Node){
    return abs(nodeHeight(Node->Left) - nodeHeight(Node->Right));
}

int greatestBetween(int Value1, int Value2){
    if(Value1 > Value2){
        return Value1;
    }else{
        return Value2;
    }
}   

void LLRotation(AVL_BinaryTree *Root){
    AVL_BinaryTree *Node;

    Node = (*Root)->Left;   
    (*Root)->Left = (*Node)->Right;
    (*Node)->Right = (*Root);

    (*Root)->nodeHeight = greatestBetween(nodeHeight((*Root)->Left), nodeHeight((*Root)->Right)) + 1;

    (*Node)->nodeHeight = greatestBetween(nodeHeight((*Node)->Left), (*Root)->nodeHeight) + 1;

    (*Root) = Node;
}

void RRRotation(AVL_BinaryTree *Root){
    AVL_BinaryTree *Node;

    Node = (*Root)->Right;   
    (*Root)->Right = (*Node)->Left;
    (*Node)->Left = (*Root);

    (*Root)->nodeHeight = greatestBetween(nodeHeight((*Root)->Left), nodeHeight((*Root)->Right)) + 1;

    (*Node)->nodeHeight = greatestBetween(nodeHeight((*Node)->Left), (*Root)->nodeHeight) + 1;

    (*Root) = Node;
}

void LRRotation(AVL_BinaryTree *Root){
    RRRotation(&(*Root)->Left);
    LLRotation(Root);
}

void RLRotation(AVL_BinaryTree *Root){
    LLRotation(&(*Root)->Right);
    RRRotation(Root);
}

void insertInAVLTree(AVL_BinaryTree *Root, int Value){

    if((*Root) == NULL){
        AVL_BinaryTree newNode = (AVL_BinaryTree)malloc(sizeof(AVL_BinaryTree));
        newNode->Value = Value;
        newNode->nodeHeight = 0;
        newNode->Left = NULL;
        newNode->Right = NULL;
        *Root = newNode;
        printf("\n Successfully inserted value!\n");
    }else{
        AVL_BinaryTree currentNode = *Root;

        if(Value < currentNode->Value){
            insertInAVLTree(&currentNode->Left, Value);
            if(balancingFactor(currentNode) >= 2){
                if(Value < (*Root)->Left->Value){
                    LLRotation(Root);
                }else{
                    LRRotation(Root);
                }
            }
        }else if(Value > currentNode->Value){
            insertInAVLTree(&currentNode->Left, Value);
            if(balancingFactor(currentNode) >= 2){
                if(Value > (*Root)->Right->Value){
                    RRRotation(Root);
                }else{
                    RLRotation(Root);
                }
            }
        }else{
            printf("\n Duplicate value!\n");
        }

        currentNode->nodeHeight = greatestBetween(nodeHeight(currentNode->Left), nodeHeight(currentNode->Right)) + 1;
    }
}
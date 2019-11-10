#ifndef ARVORE_BINARIA_DINAMICA
#define ARVORE_BINARIA_DINAMICA

typedef struct Node {
    struct Node *Left;
    int Value;
    struct Node *Right;
}*BinaryTree;

BinaryTree* createBinaryTree();

void freeTree(BinaryTree *Root);

void freeNodes(BinaryTree Node);

int isEmpty(BinaryTree *Root);

int treeHeight(BinaryTree *Root);

int totalNodes(BinaryTree *Root);

#endif
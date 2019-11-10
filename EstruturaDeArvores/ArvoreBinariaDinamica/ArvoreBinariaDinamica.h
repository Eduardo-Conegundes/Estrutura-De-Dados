#ifndef ARVORE_BINARIA_DINAMICA
#define ARVORE_BINARIA_DINAMICA

typedef struct Node {
    struct Node *Left;
    int Value;
    struct Node *Right;
}*BinaryTree;

BinaryTree* createBinaryTree();


#endif
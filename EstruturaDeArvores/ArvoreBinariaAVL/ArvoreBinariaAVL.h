#ifndef ARVORE_BINARIA_DINAMICA
#define ARVORE_BINARIA_DINAMICA

typedef struct Node {
    int nodeHeight;
    struct Node *Left;
    int Value;
    struct Node *Right;
}*AVL_BinaryTree;

AVL_BinaryTree* createBinaryTree();

void freeTree(AVL_BinaryTree *Root);

int balancingFactor(AVL_BinaryTree Node);

int nodeHeight(AVL_BinaryTree Node);

void freeNodes(AVL_BinaryTree Node);

int isEmpty(AVL_BinaryTree *Root);

int treeHeight(AVL_BinaryTree *Root);

int totalNodes(AVL_BinaryTree *Root);

void Inorder(AVL_BinaryTree *Root);

void Preorder(AVL_BinaryTree *Root);

void Postorder(AVL_BinaryTree *Root);

int greatestBetween(int Value1, int Value2);

void insertInTree(AVL_BinaryTree *Root, int Value);

void removeNode(AVL_BinaryTree *Root, int Value);

AVL_BinaryTree removeSpecificNode(AVL_BinaryTree Node);

void lookForValue(AVL_BinaryTree *Root, int Value);

#endif
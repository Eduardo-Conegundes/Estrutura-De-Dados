#include "ArvoreBinariaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *Left;
    int Value;
    struct Node *Right;
}*BinaryTree;


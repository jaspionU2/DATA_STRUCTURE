#include <stdlib.h>
#include <stdio.h>

typedef struct BinaryTree{
    int data;
    struct BinaryTree * left_node;
    struct BinaryTree * right_node;
} BinaryTree;


BinaryTree* CreateNode(int data){
    BinaryTree * Node = (BinaryTree*) malloc(sizeof(BinaryTree));

    if (Node == NULL){
        printf("Error: failed in allocate memory for a new node");
        return NULL;
    };

    Node->data = data;
    Node->left_node = Node->right_node = NULL;

    return Node;
}
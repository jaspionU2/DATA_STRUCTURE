#include <stdlib.h>
#include <stdio.h>

typedef struct BinaryTree{
    int data;
    struct BinaryTree * left_node;
    struct BinaryTree * right_node;
} BinaryTree;

BinaryTree* root = NULL;

BinaryTree* CreateNode(int data){
    BinaryTree * Node = (BinaryTree*) malloc(sizeof(BinaryTree));

    if (Node == NULL){
        printf("Error: failed in allocate memory for a new node");
        return NULL;
    };

    Node->data = data;
    Node->left_node = Node->right_node = NULL;

    return Node;
};

BinaryTree* InsertInTree(int data, BinaryTree ** current_node){ 
    BinaryTree * node = CreateNode(data);

    if (root == NULL){
        root = node;
        return;
    }

    if (data < (*current_node)->data && (*current_node)->left_node == NULL){
        (*current_node)->left_node = node;
        return current_node;
    }
    if (data > (*current_node)->data && (*current_node)->right_node == NULL){
       (*current_node)->right_node = node;
       return current_node;
    }

    InsertInTree(data, current_node);
    return;
}
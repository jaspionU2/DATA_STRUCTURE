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
    if (*current_node == NULL){
        *current_node = CreateNode(data);
        return;
    }

    if (data < (*current_node)->data){
        if ((*current_node)->left_node == NULL){
            (*current_node)->left_node = CreateNode(data);
            return *current_node;
        }
        (*current_node)->left_node = InsertInTree(data, &((*current_node)->left_node));
        return *current_node;
    } else if (data > (*current_node)->data) {
         if ((*current_node)->right_node == NULL){
            (*current_node)->right_node = CreateNode(data);
            return *current_node;
        }
        (*current_node)->right_node = InsertInTree(data, &((*current_node)->right_node));
        return *current_node;
    }
    
}
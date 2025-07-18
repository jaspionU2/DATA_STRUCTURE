#include <stdlib.h>
#include <stdio.h>

typedef struct BinaryTree{
    int data;
    struct BinaryTree * left_node;
    struct BinaryTree * right_node;
} BinaryTree;

BinaryTree* root = NULL;

BinaryTree* CreateNode(int data);
void InsertInTree(int data, BinaryTree ** current_node);
BinaryTree* SearchInList(int data_searched, BinaryTree ** current_node);

int main(){
    InsertInTree(20, &root);
    InsertInTree(10, &root);
    InsertInTree(5, &root);
    InsertInTree(30, &root);
    InsertInTree(30, &root);
    SearchInList(5, &root);
    

    return 0;
}

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

void InsertInTree(int data, BinaryTree ** current_node){ 
    if (*current_node == NULL){
        *current_node = CreateNode(data);
        return;
    }
    
      if (data < (*current_node)->data){
        if ((*current_node)->left_node == NULL){
            (*current_node)->left_node = CreateNode(data);
            return;
        }
        InsertInTree(data, &((*current_node)->left_node));
      } else {
        if ((*current_node)->right_node == NULL){
            (*current_node)->right_node = CreateNode(data);
            return;
        }
        InsertInTree(data, &((*current_node)->right_node));
      }
   
};

BinaryTree* SearchInList(int data_searched, BinaryTree ** current_node){
    if (*current_node == NULL || (*current_node)->data == data_searched){
        return *current_node;
    }

    if (data_searched < (*current_node)->data){
        SearchInList(data_searched, &((*current_node)->left_node));
    } else {
        SearchInList(data_searched, &((*current_node)->right_node));
    }
}

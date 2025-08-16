#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct BinaryTree
{
    int data;
    struct BinaryTree *left_node;
    struct BinaryTree *right_node;
} BinaryTree;

BinaryTree *_root = NULL;

BinaryTree *CreateNode(int data);
void InsertInTree(int data, BinaryTree **current_node);
BinaryTree *SearchInList(int data_searched, BinaryTree **current_node);
void ShowList(BinaryTree *current_node, int level_identation);
BinaryTree *PredecessorInOrder(BinaryTree ** node);
void DeleteNode(BinaryTree **father_node, BinaryTree **current_node, int node_to_delete);

int main()
{
    InsertInTree(20, &_root);
    InsertInTree(10, &_root);
    InsertInTree(15, &_root);
    InsertInTree(5, &_root);
    InsertInTree(30, &_root);
    InsertInTree(40, &_root);
    ShowList(_root, 0);
    printf("-------------------------\n");
    DeleteNode(&_root, &_root, 20);
    ShowList(_root, 0);

    return 0;
}

BinaryTree *CreateNode(int data)
{
    BinaryTree *Node = (BinaryTree *)malloc(sizeof(BinaryTree));

    if (Node == NULL)
    {
        printf("Error: failed in allocate memory for a new node");
        return NULL;
    };

    Node->data = data;
    Node->left_node = Node->right_node = NULL;

    return Node;
};

void InsertInTree(int data, BinaryTree **current_node)
{
    if (*current_node == NULL)
    {
        *current_node = CreateNode(data);
        return;
    }

    if (data < (*current_node)->data)
    {
        if ((*current_node)->left_node == NULL)
        {
            (*current_node)->left_node = CreateNode(data);
            return;
        }
        InsertInTree(data, &((*current_node)->left_node));
    }
    else
    {
        if ((*current_node)->right_node == NULL)
        {
            (*current_node)->right_node = CreateNode(data);
            return;
        }
        InsertInTree(data, &((*current_node)->right_node));
    }
};

BinaryTree *SearchInList(int data_searched, BinaryTree **current_node)
{
    if (*current_node == NULL || (*current_node)->data == data_searched)
    {
        return *current_node;
    }

    if (data_searched < (*current_node)->data)
    {
        return SearchInList(data_searched, &((*current_node)->left_node));
    }
    else
    {
        return SearchInList(data_searched, &((*current_node)->right_node));
    }
}

void ShowList(BinaryTree *current_node, int level_identation)
{
    if (current_node == NULL)
    {
        return;
    }

    ShowList(current_node->right_node, level_identation + 1);

    for (int i = 0; i < level_identation; i++)
    {
        printf("    ");
    }

    printf("--> %d\n", current_node->data);

    ShowList(current_node->left_node, level_identation + 1);
}

BinaryTree *PredecessorInOrder(BinaryTree ** node) {
    if((*node)->right_node != NULL){
        return PredecessorInOrder(&(*node)->right_node);
    } else {
        BinaryTree *auxiliar = *node;
        if ((*node)->left_node != NULL) {
            *node = (*node)->left_node;
        } else {
            *node = NULL;
        }
        return auxiliar;
    }
}

void DeleteNode(BinaryTree **father_node, BinaryTree **current_node, int node_to_delete)
{
    if ((*current_node) == NULL)
    {
        return;
    }

    if (node_to_delete == (*current_node)->data)
    {
        // bool position_node = node_to_delete < (*father_node)->data;

        if ((*current_node)->left_node == NULL && (*current_node)->right_node == NULL)
        {
            free((*current_node));
            *current_node = NULL;
            return;
        }
        else if ((*current_node)->left_node == NULL) 
        {
            BinaryTree *temp = *current_node;
            (*current_node) = (*current_node)->right_node;
            free(temp);
            temp = NULL;
            return;
        }
        else if ((*current_node)->right_node == NULL) 
        {
           BinaryTree *temp = *current_node;
           (*current_node) = (*current_node)->right_node;
           free(temp);
           temp = NULL;
           return;
        }
        else
        {
            BinaryTree *temp = *current_node;
            temp = PredecessorInOrder(&(*current_node)->left_node);
            temp->left_node = (*current_node)->left_node;
            temp->right_node = (*current_node)->right_node;
            (*current_node)->left_node = (*current_node)->right_node = NULL;
            free((*current_node));
            *current_node = temp;
            temp = NULL;
        }
    }

    if (node_to_delete < (*current_node)->data)
    {
        DeleteNode(&(*current_node), &((*current_node)->left_node), node_to_delete);
    }
    else
    {
        DeleteNode(&(*current_node), &((*current_node)->right_node), node_to_delete);
    }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *nextNode;
} Node;

Node * head = NULL;

Node* CreateNode(int value);
void InsertAtEnd(int value);
void InsertAtEnd(int value);
void ShowList();

int main(){
   int valor;
   int controller = 1;

   while (controller != 0){
        printf("Insira um valor para adicionar a lista. Para sair digite [0]");
        scanf("%d", &valor);

        if (valor == 0){
            break;
        }

        

    }

    return 0;
}

Node* CreateNode(int value){
    Node * newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL){
        printf("\nErro ao alocar memoria\n");
        return NULL;
    }

    newNode->info = value;
    newNode->nextNode = NULL;

    return newNode;
};

void InsertAtBeginning(int value){
    Node * node = CreateNode(value);

    if (head == NULL){
        head = node;
        return;
    }

    node->nextNode = head;
    head = node;
};

void InsertAtEnd(int value){
    Node * node = CreateNode(value);

    if (head == NULL){
        head = node;
        return;
    }

    Node * auxiliar = head;

    while (auxiliar->nextNode != NULL){
        auxiliar = auxiliar->nextNode;
    }

    auxiliar->nextNode = node;

};

void ShowList(){
    if (head == NULL){
        return;
    }

    Node * auxiliar = head;

    while (auxiliar->nextNode != NULL){
        printf("[%d] --> ", auxiliar->info);
        auxiliar = auxiliar->nextNode;
    }

    printf("[%d] --> NULL\n", auxiliar->info);
};
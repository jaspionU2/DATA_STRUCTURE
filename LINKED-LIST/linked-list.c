#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *nextNode;
} Node;

Node * head = NULL;

Node* CreateNode(int value);
void InsertAtBeginning(int value);
void InsertAtEnd(int value);
void ShowList();
Node* SearchNode(int value_seeked);
void DeleteNode(int node_to_delete);
void ClearList();

int main(){
    int choice;
    int data;
    Node *foundNode;

    do {
        printf("\n--- Gerenciamento de Lista Encadeada ---\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Procurar um no\n");
        printf("4. Apagar um no\n");
        printf("5. Listar todos os nos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor para inserir no inicio: ");
                scanf("%d", &data);
                InsertAtBeginning(data);
                break;
            case 2:
                printf("Digite o valor para inserir no fim: ");
                scanf("%d", &data);
                InsertAtEnd(data);
                break;
            case 3:
                printf("Digite o valor do no a procurar: ");
                scanf("%d", &data);
                foundNode = SearchNode(data);
                if (foundNode != NULL) {
                    printf("No com valor %d encontrado no endereco de memoria %p.\n", data, (void*)foundNode);
                } else {
                    printf("No com valor %d nao encontrado na lista.\n", data);
                }
                break;
            case 4:
                printf("Digite o valor do no a apagar: ");
                scanf("%d", &data);
                DeleteNode(data);
                break;
            case 5:
                ShowList();
                break;
            case 0:
                printf("Saindo do programa. Liberando memoria...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (choice != 0);

    ClearList(); 
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

Node* SearchNode(int value_seeked){
    Node * current_node = head;

    while (current_node != NULL && current_node->info != value_seeked){
        current_node = current_node->nextNode;
    }

    return current_node;
};

void DeleteNode(int node_to_delete){
    Node * current_node = head;
    Node * previous_node;

    while (current_node != NULL && current_node->info != node_to_delete){
        previous_node = current_node;
        current_node = current_node->nextNode;
    }

    if (current_node == NULL){
        return;
    }

    if (current_node == head){
        head = current_node->nextNode;
    } else {
        previous_node->nextNode = current_node->nextNode;
    }

    free(current_node);
};

void ClearList(){
    Node * current_node = head;
    Node * next_node;

    while (current_node != NULL){
        next_node = current_node->nextNode;
        free(current_node);
        current_node = next_node;
    }

    head = NULL;

    return;
}
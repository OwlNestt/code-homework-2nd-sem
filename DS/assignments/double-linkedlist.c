// 8.	To implement double linked list and perform operations such as node insert and delete.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current; // Link the new node to the last node
}
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    if (current == NULL) return; // Key not found

    if (current->prev != NULL) {
        current->prev->next = current->next; // Link previous node to next node
    } else {
        *head = current->next; // If it's the head node
    }
    if (current->next != NULL) {
        current->next->prev = current->prev; // Link next node to previous node
    }
    free(current);
}

void main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Print the double linked list
    struct Node* current = head;
    printf("Forward traversal: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Delete a node
    deleteNode(&head, 20);

    // Print the list after deletion
    current = head;
    printf("After deletion: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
        
}
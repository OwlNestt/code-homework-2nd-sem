// 7.	To implement circular linked list and perform operations such as node insert and delete.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}   
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Point to itself
        return;
    }
    struct Node* current = *head;
    while (current->next != *head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = *head; // Make it circular
}

void main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Print the circular linked list
    struct Node* current = head;
    if (current != NULL) {
        do {
            printf("%d -> ", current->data);
            current = current->next;
        } while (current != head);
        printf("(back to head)\n");
    } else {
        printf("List is empty.\n");
    }
}

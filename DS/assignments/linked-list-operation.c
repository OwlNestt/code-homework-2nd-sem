// 6.	To implement linear linked list and perform operations such as traverse, search, insert, delete, and reversing the list.

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
void traverse(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
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
}
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return;

    prev->next = current->next;
    free(current);
}
void search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            printf("Element %d found in the list.\n", key);
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list.\n", key);
}
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;       
    }
    *head = prev; 
}
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Linked List after insertion: ");
    traverse(head);

    search(head, 20);
    search(head, 50);

    deleteNode(&head, 20);
    printf("Linked List after deleting 20: ");
    traverse(head);

    reverseList(&head);
    printf("Linked List after reversing: ");
    traverse(head);

    return 0;
}
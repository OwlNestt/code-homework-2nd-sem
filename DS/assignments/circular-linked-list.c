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

struct Node *deleteNode(struct Node** head, int key) {
    if (*head == NULL) return NULL;

    struct Node *current = *head, *prev = NULL;

    // If the node to be deleted is the head
    if (current->data == key) {
        if (current->next == *head) { // Only one node in the list
            free(current);
            *head = NULL;
            return NULL;
        } else {
            // Find the last node to update its next pointer
            while (current->next != *head) {
                current = current->next;
            }
            current->next = (*head)->next;
            free(*head);
            *head = current->next;
            return *head;
        }
    }

    // Search for the node to delete
    while (current->next != *head && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the node was found
    if (current->data == key) {
        prev->next = current->next;
        free(current);
    }
    
    return *head;
}

int main() {
    int choice = -1, data, key;
    struct Node* head = NULL;
    struct Node* temp = NULL;
    while (1) {
        printf("\nMenu:\n1. Insert node\n2. Delete node\n3. Display list\n0. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter data to insert: ");
            scanf("%d", &data);
            struct Node* newNode = createNode(data);
            if (head == NULL) {
                head = newNode;
                head->next = head; // Point to itself to make it circular
            } else {
                temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head; // Point the new node to the head
            }
            printf("Node inserted.\n");
        } else if (choice == 2) {
            if (head == NULL) {
                printf("List is empty.\n");
            } else {
                printf("Enter data to delete: ");
                scanf("%d", &key);
                struct Node* prev_head = head;
                head = deleteNode(&head, key);
                if (head == prev_head) {
                    printf("Node deleted if present.\n");
                } else if (head == NULL) {
                    printf("Node deleted. List is now empty.\n");
                } else {
                    printf("Node deleted if present.\n");
                }
            }
        } else if (choice == 3) {
            if (head == NULL) {
                printf("List is empty.\n");
            } else {
                printf("Circular Linked List: ");
                temp = head;
                do {
                    printf("%d ", temp->data);
                    temp = temp->next;
                } while (temp != head);
                printf("\n");
            }
        } else if (choice == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    // Free all nodes
    if (head != NULL) {
        struct Node* curr = head->next;
        struct Node* nextNode;
        while (curr != head) {
            nextNode = curr->next;
            free(curr);
            curr = nextNode;
        }
        free(head);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to traverse forward
void traverseForward(struct Node* head) {
    printf("\nForward Traversal: ");
    while (head != NULL) {
        printf("<-%d->", head->data);
        head = head->next;
    }
}

// Function to traverse backward
void traverseBackward(struct Node* head) {
    struct Node* last = head;
    printf("\nBackward Traversal: ");
    while (last->next != NULL) {
        last = last->next;
    }
    while (last != NULL) {
        printf("<-%d->", last->data);
        last = last->prev;
    }
}

// Function to delete a node with given value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("\nList is empty!");
        return;
    }
    
    struct Node* current = *head;
    
    // If head node itself holds the key
    if (current->data == key) {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        printf("\nNode deleted successfully!");
        return;
    }
    
    while (current != NULL && current->data != key)
        current = current->next;
        
    if (current == NULL) {
        printf("\nValue not found!");
        return;
    }
    
    // Update prev and next pointers
    if (current->next != NULL)
        current->next->prev = current->prev;
    current->prev->next = current->next;
    
    free(current);
    printf("\nNode deleted successfully!");
}

// Function to search a value
void searchNode(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;
    
    while (current != NULL) {
        if (current->data == key) {
            printf("\nValue found at position %d", position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("\nValue not found!");
}

int main() {
    struct Node* head = NULL;
    int choice, data, searchKey, deleteKey;
    
    while (1) {
        printf("\n\nDoubly Linked List Operations:");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Forward Traversal");
        printf("\n5. Backward Traversal");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                printf("\nNode inserted successfully!");
                break;
                
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &deleteKey);
                deleteNode(&head, deleteKey);
                break;
                
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &searchKey);
                searchNode(head, searchKey);
                break;
                
            case 4:
                traverseForward(head);
                break;
                
            case 5:
                if (head != NULL)
                    traverseBackward(head);
                else
                    printf("\nList is empty!");
                break;
                
            case 6:
                exit(0);
                
            default:
                printf("\nInvalid choice!");
        }
    }
    
    return 0;
}
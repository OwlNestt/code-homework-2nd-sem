#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end
void insert(struct Node** head) {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    
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
}

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node with given value
void delete(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);
    
    struct Node *temp = *head, *prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node deleted successfully!\n");
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }
    
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully!\n");
}

// Function to search a value
void search(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    int key, position = 1;
    printf("Enter value to search: ");
    scanf("%d", &key);
    
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value found at position %d\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value not found!\n");
}

int main() {
    struct Node* head = NULL;
    int choice;
    
    do {
        printf("\n1. Insert\n2. Display\n3. Delete\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: insert(&head); break;
            case 2: display(head); break;
            case 3: delete(&head); break;
            case 4: search(head); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);
    
    return 0;
}
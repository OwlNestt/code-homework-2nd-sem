#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function prototypes
struct node* insertNode(struct node* head);
struct node* deleteNode(struct node* head, int value);
void traverse(struct node* head);

// Function to insert a new node
struct node* insertNode(struct node* head) {
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter a value: ");
    scanf("%d", &newNode->data);
    
    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

// Function to delete a node with given value
struct node* deleteNode(struct node* head, int value) {
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    
    struct node *current = head, *prev = NULL;
    
    // If head node itself holds the value
    if(current->data == value) {
        if(current->next == head) {
            free(current);
            return NULL;
        }
        while(current->next != head) {
            current = current->next;
        }
        current->next = head->next;
        free(head);
        return current->next;
    }
    
    // Search for the node to be deleted
    while(current->next != head && current->data != value) {
        prev = current;
        current = current->next;
    }
    
    if(current->data == value) {
        prev->next = current->next;
        free(current);
    } else {
        printf("Value not found in the list\n");
    }
    return head;
}

// Function to traverse and print the list
void traverse(struct node* head) {
    struct node *temp = head;
    if(head != NULL) {
        do {
            printf("%d->", temp->data);
            temp = temp->next;
        } while(temp != head);
        printf("\n");
    } else {
        printf("List is empty\n");
    }
}

int main() {
    struct node *head = NULL;
    int choice, value;
    
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                head = insertNode(head);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);
    
    return 0;
}
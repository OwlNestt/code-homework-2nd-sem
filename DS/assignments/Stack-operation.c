// 8. perform stack operations using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int count = 0; 
int isOverflow(int size) {
    return count >= size;
}

int isUnderflow() {
    return count == 0;
}

void peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

// Function to pop an element from the stack
void pop(struct Node** top) {
    if (isUnderflow()) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = *top;
    printf("Popped element: %d\n", temp->data);
    *top = (*top)->next;
    free(temp);
    count--;
}

// Function to push an element onto the stack
void push(struct Node** top, int size) {
    if (isOverflow(size)) {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to push onto the stack: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (*top == NULL) {
        *top = newNode; 
    } else {
        newNode->next = *top; 
        *top = newNode; 
    }
    count++;
}

int main(){
    struct Node* top = NULL;
    int size = 10; 
    int choice = 1; 
    while(choice != 0){
        push(&top, size);
        if (isOverflow(size)) {
            break;
        }
        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    }

    // Stack operation menu
    do {
        printf("\nStack Operations:\n");
        printf("1. Pop\n2. Peek\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: pop(&top); break;
            case 2: peek(top); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 3);

    // Free remaining nodes
    while(top != NULL) {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
    return 0;
}
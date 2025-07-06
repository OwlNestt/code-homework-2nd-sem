// 11. Array and Linked list implementations of Stack and perform operations such as push, pop and status.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

int count = 0; // To keep track of stack size
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
        *top = newNode; // If stack is empty, new node becomes the top
    } else {
        newNode->next = *top; // Link new node to the previous top
        *top = newNode; // Update top to the new node
    }
    count++;
}

int main() {
    struct Node* top = NULL;
    int size = 10; // Initial size of the stack
    int choice = 1; // choice for loop control

    while (choice != 0) {
        printf("1. Push\n2. Pop\n3. Peek\n4. Check Overflow\n5. Check Underflow\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(&top, size); break;
            case 2: pop(&top); break;
            case 3: peek(top); break;
            case 4: isOverflow(size) ? printf("Stack is full.\n") : printf("Stack is not full.\n"); break;
            case 5: isUnderflow() ? printf("Stack is empty.\n") : printf("Stack is not empty.\n"); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


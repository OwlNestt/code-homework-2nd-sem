#include <stdio.h>
#include <stdlib.h>

// Define the structure for stack node
struct Node {
    int data;
    struct Node* next;
};

// Global top pointer
struct Node* top = NULL;

// Function to check if stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack underflow!\n");
        return -1;
    }
    struct Node* temp = top;
    int popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}

// Function to peek at the top element
int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}

// Function to display the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack implementation
int main() {
printf("Size of struct Node: %zu bytes\n", sizeof(struct Node));
    push(10);
    push(20);
    push(30);
    
    display();
    
    printf("Top element is %d\n", peek());
    printf("Popped element: %d\n", pop());
    
    display();
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    (*newNode).data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Create nodes
    struct Node* head = createNode(10);
    struct Node* temp = head;
    head->next = createNode(20);
    head->next->next = createNode(30);
    printf("How many nodes do you want to insert? ");
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++ ){
        int v;
        printf("Enter the value of node %d: ", i+1);
        scanf("%d", &v);
        struct Node* newNode = createNode(v);
        temp->next = newNode;
    }

    // Print the list
    printList(head);

    return 0;
}

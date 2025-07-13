// 9. To represent a Sparse Matrix using linked list.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new non-zero element into the linked list
void insert(struct Node** head, int row, int col, int value) {
    if (value == 0) return; // skip zero values

    struct Node* newNode = createNode(row, col, value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to display the sparse matrix in (row, col, value) format
void display(struct Node* head) {
    printf("Row\tCol\tValue\n");
    while (head != NULL) {
        printf("%d\t%d\t%d\n", head->row, head->col, head->value);
        head = head->next;
    }
}

int main() {
    int rows, cols;
    
    // Get matrix dimensions from user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    struct Node* head = NULL;

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &value);
            if (value != 0) {
                insert(&head, i, j, value);
            }
        }
    }

    // Display the sparse matrix
    printf("\nSparse Matrix Representation using Linked List:\n");
    display(head);

    return 0;
}


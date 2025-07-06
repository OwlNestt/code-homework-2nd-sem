// 12. Linked list implementation of Queue and perform operations such as enqueue and dequeue.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

stuct Node* enqueue(struct Node* rear, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return rear;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        return newNode; // If queue is empty, new node becomes both front and rear
    } else {
        rear->next = newNode; // Link the new node at the end of the queue
        return newNode; // Update rear to the new node
    }
}

struct Node* dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue is empty!\n");
        return NULL;
    }
    struct Node* temp = *front;
    *front = (*front)->next; // Move front to the next node
    return temp; // Return the dequeued node
}

void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value;

    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                rear = enqueue(rear, value);
                if (front == NULL) {
                    front = rear; // If queue was empty, set front to the new rear
                }
                break;
            case 2:
                {
                    struct Node* dequeuedNode = dequeue(&front);
                    if (dequeuedNode != NULL) {
                        printf("Dequeued: %d\n", dequeuedNode->data);
                        free(dequeuedNode); // Free the memory of the dequeued node
                    }
                }
                break;
            case 3:
                displayQueue(front);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    // Free remaining nodes in the queue
    while (front != NULL) {
        struct Node* temp = dequeue(&front);
        free(temp);
    }

    return 0;
}


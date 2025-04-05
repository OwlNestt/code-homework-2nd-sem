#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertStart(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insertEnd(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
        return;
    }
    struct node *last = head;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = temp;
}

void insertPos(int x, int pos) {
    if(pos == 1) {
        insertStart(x);
        return;
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    struct node *curr = head;
    for(int i = 1; i < pos-1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if(curr == NULL) {
        printf("Position out of range\n");
        return;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void updateNode(int x, int pos) {
    struct node *curr = head;
    for(int i = 1; i < pos && curr != NULL; i++) {
        curr = curr->next;
    }
    if(curr == NULL) {
        printf("Position not found\n");
        return;
    }
    curr->data = x;
}

void deleteStart() {
    if(head == NULL) return;
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd() {
    if(head == NULL) return;
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node *curr = head;
    while(curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
}

void deletePos(int pos) {
    if(head == NULL) return;
    if(pos == 1) {
        deleteStart();
        return;
    }
    struct node *curr = head;
    for(int i = 1; i < pos-1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if(curr == NULL || curr->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct node *temp = curr->next;
    curr->next = temp->next;
    free(temp);
}

void display() {
    struct node *curr = head;
    while(curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, x, pos;
    while(1) {
        printf("\n1. Insert at start\n2. Insert at end\n3. Insert at position");
        printf("\n4. Update at position\n5. Delete from start\n6. Delete from end");
        printf("\n7. Delete from position\n8. Display\n9. Exit\nEnter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertStart(x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertEnd(x);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &x, &pos);
                insertPos(x, pos);
                break;
            case 4:
                printf("Enter value and position: ");
                scanf("%d %d", &x, &pos);
                updateNode(x, pos);
                break;
            case 5:
                deleteStart();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
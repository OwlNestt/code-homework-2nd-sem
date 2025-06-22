#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(){
    struct node *newNode, *head, *temp;
    int ch;
    head = NULL;
    while(ch != 0){
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter a value: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if(head == NULL){
           temp = head = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
        printf("want to continue (0/1): ");
        scanf("%d",&ch);
    }
    temp = head;
    int num,counter=0;
    printf("Enter element want to delete: ");
    scanf("%d",&num);
    printf("Before Delete: ");
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    } printf("\n");

    // element delete logic
    struct node *prev = NULL;
temp = head;
while (temp != NULL) {
    if (temp->data == num) {
        if (prev == NULL) {
            // Deleting the head node
            head = temp->next;
            free(temp);
            temp = head;
        } else {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        }
        break;
    } else {
        prev = temp;
        temp = temp->next;
    }
}

    printf("After Delete: ");
    temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    } printf("\n");

    return 0;
}
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
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }

    return 0;
}
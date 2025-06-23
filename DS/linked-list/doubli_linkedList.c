#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

int main(){

    struct node *newNode, *head, *temp;
    head = NULL;
    int ch;
    while(ch != 0){
        newNode = (struct node*) malloc(sizeof(struct node));
        printf("Enter element: ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        if(head == NULL)
            temp = head = newNode;
        else{
            temp->next = newNode;
            newNode->prev = temp;
            temp  = newNode;
        }
        printf("Want to continue (1/0): ");
        scanf("%d",&ch);
    }

    while(temp != head){
        printf("%d->",temp->data);
        temp = temp->prev;
    }

    return 0;
}
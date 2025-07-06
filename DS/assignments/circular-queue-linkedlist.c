// 13. Linked list implementation of Circular Queue.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main(){
    struct Node *head=NULL, *temp=NULL, *newnode;
    int choice = 1; 
    while(choice !=0){
        newnode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL) {
            head = temp = newnode; 
        } else {
            temp->next = newnode; 
            temp = newnode; 
        }
        temp->next = head; 
        printf("Do you want to continue (1/0): ");  
        scanf("%d", &choice);
    }
    temp = head;
    if (temp != NULL) {
        do {
            printf("%d -> ", temp->data); 
            temp = temp->next; 
        } while (temp != head);
    }

}

#include<stdio.h>
#include<string.h>

void Display(int arr[], int index){
    for(int i=index; i>-1; i--){
        printf("%d\n",arr[i]);
    }
} 

void Push(int arr[], int* index, int size){
    if(*index > size-1){
        printf("Overflow");
    } else {
        int n,item;
        printf("How many Items you want:"); scanf("%d",&n);
        printf("Enter element separated by space: "); 
        for(int i=0; i<n; i++){
            (*index)++;
            scanf("%d",&item);
            arr[*index] = item;
        }
    }
}

void main(){
    int arr[100];
    int size,item, index=-1;
    char choice;
    printf("Enter Stack size you want:"); scanf("%d",&size);
    do {
        
    printf("What operation you want press 'p' (for push)\t'd' for (POP)\t's' for (peek)\t'v' for show\t'q' for quit\t You: "); scanf("%s",&choice);
    if(choice == 'p'){
        // if(index>= size){
        //     printf("Overflow");
        // } else {
        //     int n;
        // printf("How many elements want to push (you can't push more then %d ): "); scanf("%d",&n);
        // printf("Enter Element separeted by space : ");
        // for(int i=0; i<n; i++){
        //     index++;
        //     scanf("%d", &item);
        //     arr[index]= item;
        // }
        // }
        Push(arr, &index, size);
    } else if (choice == 'd'){
        if(index <= -1){
            printf("Underflow");
        } else {
            index--;
            printf("One item POP\n");
        }
        
    } else if (choice == 's'){
        continue;
    } else if (choice== 'v'){
        Display(arr, index);
    }
    } while(choice != 'q');

}
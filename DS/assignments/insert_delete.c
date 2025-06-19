// 2.	To insert and delete elements into/from appropriate position in an array.
#include<stdio.h>

int Insert(int arr[], int pos, int size){
    if(pos < 0 || pos > size){
        printf("Invalid position\n");
        return -1;
    }
    int element;
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    
    for(int i = size; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    
    printf("Element inserted successfully\n");
    return 0;

}
int Delete(int arr[], int pos, int size){
    if(pos < 0 || pos >= size){
        printf("Invalid position\n");
        return -1;
    }
    
    for(int i = pos; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }
    
    printf("Element deleted successfully\n");
    return 0;

}
void main(){
    int arr[] = {10,20,14,16,19,10,5,16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice, pos;
    printf("\n1. Insert Element\n2. Delete Element\n3. Print Array\n4. Exit\n");
    while(1){
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &pos);
                if(Insert(arr, pos,size) == 0) size++; break;
            case 2:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &pos);
                if(Delete(arr, pos, size) == 0) size--; break;
            case 3:
                printf("Array elements: ");
                for(int i = 0; i < size; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            case 4:
                return;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}
// 1.	To search an element and print the total occurrences in the array.
#include<stdio.h>

void main(){
    int arr[] = {10,15,3,67,90,3,21,86,15,19,143,10,15,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element, couter=0;
    printf("Enter the Array element you want to search: ");
    scanf("%d",&element);
    for(int i=0; i<size; i++){
        if(element == arr[i]){
            couter++;
        }
    }
    couter > 0 ? printf("Entered element found\nOccurence: %d times",couter) : printf("Entered element Not found");
}
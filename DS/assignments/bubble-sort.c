// 4.	To perform Bubble sort.
#include<stdio.h>

void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) 
            if(arr[j] > arr[j + 1]) 
                arr[j] = arr[j] + arr[j + 1] - (arr[j + 1] = arr[j]);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, size);
    
    printf("Sorted array: \n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
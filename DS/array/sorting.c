#include<stdio.h>
// Function for bubble sort
int bubbleSort(int arr[], int size ){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
               int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int SelectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int min_ind = i;
        for(int j=i+1; j<size; j++){
            if(arr[j]< arr[min_ind])
                min_ind = j;
        }
        int temp = arr[min_ind];
        arr[min_ind] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    
    int arr[]={4,5,1,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    // bubbleSort(arr,size);
    SelectionSort(arr, size);
    for(int i=0; i<size; i++)
        printf("%d\t",arr[i]);
}
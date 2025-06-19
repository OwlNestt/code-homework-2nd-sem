// 5.	To perform Selection sort.
#include<stdio.h>

int SelectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int min_ind = i;
        for(int j = i + 1; j < size; j++)
            if(arr[j] < arr[min_ind]) min_ind = j;

        arr[i] = arr[i] + arr[min_ind] - (arr[min_ind] = arr[i]);
    }
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: \n");
    for(int i = 0; i < size; i++)printf("%d ", arr[i]); printf("\n");
    
    printf("After sorting: \n");
    SelectionSort(arr, size);
    for(int i = 0; i < size; i++) printf("%d ", arr[i]); printf("\n");
    
    return 0;
}
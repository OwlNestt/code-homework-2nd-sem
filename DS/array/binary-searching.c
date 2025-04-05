#include<stdio.h>
int sort(int arr[],int size);
int binarySearch(int arr[], int size,int item);
int main()
{
    int arr[] = {1,4,6,2,8,0},s,item;
    s= sizeof(arr) / sizeof(arr[0]);
    sort(arr,s);
    for(int j=0; j<s; j++)
    {
        printf("%d\t",arr[j]);
    }
    printf("\n");

    printf("Enter Item you want to search: ");
    scanf("%d",&item);

    int ind= binarySearch(arr,s,item);
    ind ? printf("Item found at %d i.e %d", ind, arr[ind]) : printf("Item not found");

}

binarySearch(int arr[], int size,int item)
{
    int lb,ub,mid;
    lb=0,ub=size-1;
    while(lb<=ub)
    {
        mid= (lb+ub)/2;
        if(item == arr[mid])
        {
            return mid;
        }
        else if(arr[mid] < item)
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    return -1;

}

sort(int arr[],int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                arr[j] = arr[j] + arr[j+1] - (arr[j+1] = arr[j]);

            }
        }
    }
}

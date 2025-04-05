#include<stdio.h>
int main(){

    int i=0,item,s, arr[]={1,2,3,4,5,6};
    s=sizeof(arr) / sizeof(arr[0]);
    // displaying all element
    for(int j=0; j<s; j++){
        printf("%d\t",arr[j]);
    }
    printf("\n");
    printf("Enter the item you want to find: ");
    scanf("%d",&item);
   while(i<s){
    if(item == arr[i]){
        printf("Item found at index %d and i.e. %d\n",i,arr[i]);
        return 0;
        break;

    }
    i++;
   }
   printf("Your entered Item not found.\n");

    return 0;
}

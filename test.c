#include<stdio.h>

int main(){
    int a=5;
    int b=2;
    printf("a=%d\nb=%d\n",a,b);
    a = a + b - (a =b );
    printf("a=%d\nb=%d\n",a,b);
}
#include<stdio.h>
#include<string.h>

void Display(int arr[], int index) {
    for (int i = index; i > -1; i--) {
        printf("%d\n", arr[i]);
    }
}

void PUSH(int arr[], int *index, int size) {
    if (*index >= size - 1) {
        printf("Overflow\n");
    } else {
        int n, item;
        printf("How many elements do you want to push (you can't push more than %d): ", size - *index - 1);
        scanf("%d", &n);
        if (n > size - *index - 1) {
            printf("You can't push more than %d elements.\n", size - *index - 1);
            return;
        }
        printf("Enter elements separated by space: ");
        for (int i = 0; i < n; i++) {
            (*index)++;
            scanf("%d", &item);
            arr[*index] = item;
        }
    }
}

void POP(int *index) {
    if (*index <= -1) {
        printf("Underflow\n");
    } else {
        (*index)--;
        printf("One item POPPED\n");
    }
}

void PEEK(int arr[], int index) {
    if (index <= -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is: %d\n", arr[index]);
    }
}

void main() {
    int arr[100];
    int size, index = -1;
    char choice;
    printf("Enter Stack size you want: ");
    scanf("%d", &size);
    do {
        printf("What operation do you want? Press 'p' (for PUSH), 'd' (for POP), 's' (for PEEK), 'v' (for SHOW), 'q' (for QUIT): ");
        scanf(" %c", &choice);
        if (choice == 'p') {
            PUSH(arr, &index, size);
        } else if (choice == 'd') {
            POP(&index);
        } else if (choice == 's') {
            PEEK(arr, index);
        } else if (choice == 'v') {
            Display(arr, index);
        }
    } while (choice != 'q');
}
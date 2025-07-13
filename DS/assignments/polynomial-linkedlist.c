// 10. Polynomial representation using linked list.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term
struct Term {
    int coeff;
    int expo;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coeff, int expo) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->expo = expo;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert term at the end of the polynomial
void insertTerm(struct Term** head, int coeff, int expo) {
    struct Term* newTerm = createTerm(coeff, expo);

    if (*head == NULL) {
        *head = newTerm;
    } else {
        struct Term* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newTerm;
    }
}

// Function to display the polynomial
void displayPolynomial(struct Term* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->expo);
        head = head->next;
        if (head != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Term* poly = NULL;

    // Example: 5x^3 + 4x^2 + 2x^1 + 7
    insertTerm(&poly, 5, 3);
    insertTerm(&poly, 4, 2);
    insertTerm(&poly, 2, 1);
    insertTerm(&poly, 7, 0);

    printf("Polynomial representation:\n");
    displayPolynomial(poly);

    return 0;
}


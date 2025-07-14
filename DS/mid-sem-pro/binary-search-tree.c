#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Function for inorder traversal
void inorderDisplay(struct Node* root) {
    if (root != NULL) {
        inorderDisplay(root->left);
        printf("%d ", root->data);
        inorderDisplay(root->right);
    }
}

void preoderDisplay(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preoderDisplay(root->left);
        preoderDisplay(root->right);
    }
}

void postorderDisplay(struct Node* root) {
    if (root != NULL) {
        postorderDisplay(root->left);
        postorderDisplay(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the values to insert: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        if(root == NULL) {
            root = insert(root, value);
        } else {
            insert(root, value);
        }
    }
    
    printf("\nInorder traversal of the BST: ");
    inorderDisplay(root);
    printf("\n");
    
    return 0;
}
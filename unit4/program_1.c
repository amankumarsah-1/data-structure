
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createTree() {
    int data;
    struct Node *newNode;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    printf("Left child of %d:\n", data);
    newNode->left = createTree();

    printf("Right child of %d:\n", data);
    newNode->right = createTree();

    return newNode;
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node *root;

    root = createTree();

    printf("\nPreorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n");
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *root, int data) {
    if (root == NULL) {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node *minimum(struct Node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

struct Node *deleteNode(struct Node *root, int data) {
    if (root == NULL)
        return NULL;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int height(struct Node *root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int countNodes(struct Node *root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, data;

    do {
        printf("\n\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Height");
        printf("\n4. Total Nodes");
        printf("\n5. Display Inorder");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;

            case 3:
                printf("Height: %d\n", height(root));
                break;

            case 4:
                printf("Total nodes: %d\n", countNodes(root));
                break;

            case 5:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 0:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}

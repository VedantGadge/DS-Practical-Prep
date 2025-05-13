#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node
void insertNode(struct Node* root, int parentData, int data, char side) {
    if (root == NULL) {
        printf("Tree is empty! Please create the root node first.\n");
        return;
    }

    if (root->data == parentData) {
        if (side == 'L' || side == 'l') {
            if (root->left == NULL) {
                root->left = createNode(data);
                printf("Node inserted on the left of %d.\n", parentData);
            } else {
                printf("Left child of %d already exists!\n", parentData);
            }
        } else if (side == 'R' || side == 'r') {
            if (root->right == NULL) {
                root->right = createNode(data);
                printf("Node inserted on the right of %d.\n", parentData);
            } else {
                printf("Right child of %d already exists!\n", parentData);
            }
        } else {
            printf("Invalid side! Use 'L' for left or 'R' for right.\n");
        }
    } else {
        // Recursively search for the parent node
        if (root->left != NULL) {
            insertNode(root->left, parentData, data, side);
        }
        if (root->right != NULL) {
            insertNode(root->right, parentData, data, side);
        }
    }
}

// In-order traversal
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left); //recurses on left side until left leaf is found
        printf("%d ", root->data); 
        inOrderTraversal(root->right); //recurses on right side until right leaf is found
    }
}

// Pre-order traversal
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-order traversal
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data, parentData;
    char side;

    while (1) {
        printf("\nBinary Tree Operations:\n");
        printf("1. Create Root Node\n");
        printf("2. Insert Node\n");
        printf("3. Display Tree (In-order Traversal)\n");
        printf("4. Display Tree (Pre-order Traversal)\n");
        printf("5. Display Tree (Post-order Traversal)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (root == NULL) {
                    printf("Enter the value for the root node: ");
                    scanf("%d", &data);
                    root = createNode(data);
                    printf("Root node created with value %d.\n", data);
                } else {
                    printf("Root node already exists!\n");
                }
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty! Please create the root node first.\n");
                } else {
                    printf("Enter the parent node value: ");
                    scanf("%d", &parentData);
                    printf("Enter the value to insert: ");
                    scanf("%d", &data);
                    printf("Enter the side to insert (L for left, R for right): ");
                    scanf(" %c", &side);
                    insertNode(root, parentData, data, side);
                }
                break;
            case 3:
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Pre-order Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Post-order Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
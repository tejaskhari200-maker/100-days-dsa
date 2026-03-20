#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    if (data == -1) return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Build tree using level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* current = queue[front++];

        // Left child
        if (i < n) {
            current->left = createNode(arr[i++]);
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }
        }

        // Right child
        if (i < n) {
            current->right = createNode(arr[i++]);
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }
    }

    return root;
}

// Function to calculate height
int height(struct Node* root) {
    if (root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    int h = height(root);

    printf("%d\n", h);

    return 0;
}
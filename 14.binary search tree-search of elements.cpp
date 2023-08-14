#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    }

    return findMin(root->left);
}

int main() {
    struct Node* root = NULL;

    struct Node* minNode = findMin(root);

    if (minNode == NULL) {
        printf("The binary search tree is empty.\n");
    } else {
        printf("The minimum element in the binary search tree is %d.\n", minNode->data);
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int getHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(struct Node* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

struct Node* rotateRight(struct Node* node) {
    struct Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

struct Node* rotateLeft(struct Node* node) {
    struct Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }
    updateHeight(node);
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1 && data < node->left->data) {
        return rotateRight(node);
    }
    if (balanceFactor < -1 && data > node->right->data) {
        return rotateLeft(node);
    }
    if (balanceFactor > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balanceFactor < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}


void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}


int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    printf("Inorder traversal of the AVL tree: ");
    inorderTraversal(root);
    return 0;
}


 #include <stdio.h>
 #include <stdlib.h>

 typedef struct Node 
 {
    int val;
    struct Node* left;
    struct Node* right;
 }Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert (Node* root, int data) {
    if (root == NULL) {
        return (data);
    }
    if (data < root -> val) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
}
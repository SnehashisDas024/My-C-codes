#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Overflow");
		exit(1);
	}
	newNode->val = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insert(Node* root, int data) {
	if (root == NULL) {
		return createNode(data);
	} else if (data <= root->val) {
		root->left = insert(root->left, data);
	} else {
		root->right = insert(root->right, data);
	}
	return root;
}

void inorder(Node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf("%d\t", root->val);
	inorder(root->right);
}

void preorder(Node* root) {
	if (root == NULL) {
		return;
	}
	printf("%d\t", root->val);
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d\t", root->val);
}

void main() {
    Node* root = NULL;

    // Inserting sample data
    root = insert(root, 54);
    insert(root, 86);
    insert(root, 21);
    insert(root, 42);
    insert(root, 89);
    // insert(root, 60);
    // insert(root, 80);

    printf("Inorder traversal:   ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal:  ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
}

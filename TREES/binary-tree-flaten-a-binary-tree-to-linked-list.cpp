// Given a binary tree,
// flatten it into linked list in-place.
// Usage of auxiliary data structure is not allowed.
//  After flattening, left of each node should point
//  to NULL and right should contain next node in preorder.
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) {

		data = val;
		left = NULL;
		right = NULL;
	}
};

// void flatten(Node* node) {
// 	//bc
// 	if (node == NULL or (node->left == NULL and node->right == NULL)) {
// 		return;
// 	}
// 	if (node->left != NULL ) {
// 		flatten(node->left);
// 		Node* temp = node->right;
// 		node->right = node->left;
// 		node->left = NULL;
// 		Node* tail = node->right;
// 		while (tail->right != NULL) tail = tail->right;
// 		tail->right = temp;

// 	}
// 	flatten(node-> right);
// }

Node* flatten(Node* node) {
	//NOTE: i wrote this code, no need for video
	if (node == NULL) return NULL;
	if (node->left == NULL and node->right == NULL) return node; //leaf node

	flatten(node->left);
	flatten(node->right);

	if (node->left != NULL) {
		Node* tail = node->left;
		while (tail->right != NULL) {
			tail = tail->right;
		}

		Node* tempRight = node->right;
		node->right = node->left;
		node->left = NULL;
		tail->right = tempRight;
	}


	return node;
}

void inorder ( Node* node) {
	if (node == NULL) return;
	inorder(node->left);
	cout << node->data << " ";

	inorder(node->right);
}
int main() {
	//NOTE: i wrote this code, no need for video
	//LEETCODE: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
	Node* root = new Node(1);
	root-> left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	cout << "inorder: ";
	inorder(root);
	cout << endl;
	root = flatten(root);
	cout << "after flatten inorder(which will be the preorder traversal): ";
	inorder(root);

}

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
void inorder ( Node* node) {
	if (node == NULL) return;
	inorder(node->left);
	cout << node->data << " ";

	inorder(node->right);
}

Node* insertBST(Node* node, int val) {
	if (node == NULL) {
		return new Node(val);
	}
	if (val > node->data) {
		node->right = insertBST(node->right, val);
	} else {
		node->left = insertBST(node->left, val);
	}
}
int main() {
	Node* root = NULL;
	root = insertBST(root, 1);
	insertBST(root, 3);
	insertBST(root, 6);
	insertBST(root, 5);
	insertBST(root, 4);
	insertBST(root, 2);


	//   / \
	//  2   3
	// / \
	//4   5

	inorder(root);
	cout << endl;
}
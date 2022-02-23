
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
bool search(Node* node, int tar) {
	if (node == NULL)return false;
	if (node->data == tar) return true;
	if (tar > node->data) return search(node->right, tar);
	else {
		return search(node->left, tar);
	}
}
Node*  inordersuccessor(Node* root) {
	while (root->left != NULL) root = root->left;
	return root;
}
Node* deleteinBST(Node* root, int key) {
	if (key < root->data) {
		root->left = deleteinBST(root->left, key);

	}
	else if (key > root->data) {
		root->right = deleteinBST(root->right, key);
	}
	else {
		//key to be deleted is found.
		if (root->left == NULL) {
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			free(root);
			return temp;
		}
		else {
			//case 3-> root has both left and right child,
			// in this case find inorder successor from root right and swap it
			// and then delete the inorder successor by recursively calling the deleteinBST function
			Node* temp = inordersuccessor(root->right);
			root->data = temp -> data;
			root->right = deleteinBST(root->right, temp->data);

		}
	}
	return root;
}
int main() {
	Node* root = NULL;
	root = insertBST(root, 1);
	insertBST(root, 3);
	insertBST(root, 6);
	insertBST(root, 5);
	insertBST(root, 4);
	insertBST(root, 2);
	inorder(root);
	cout << endl;
	root = deleteinBST(root, 2);
	inorder(root);

}
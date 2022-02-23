#include <bits/stdc++.h>
using namespace std;

// max no of nodes in a BT of height H is 2^H -1.
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
int search(int start, int end, int inorder[], int key) {
	for (int i = start; i <= end; i++) {
		if (inorder[i] == key) return i;
	}
	return -1;
}
Node* buildtree (int post[], int in[], int start, int end) {
	static int ind = 4;
	if (start > end) return NULL;
	int curr = post[ind];
	ind--;
	Node* node = new Node(curr);
	if (start == end ) return node;
	int pos = search(start, end, in, curr);
	// remember first call for right then for left.
	// in case of building tree from preorder first call for left then
	// for right
	node->right = buildtree(post, in, pos + 1, end);

	node->left = buildtree(post, in, start, pos - 1);

	return node;
}
void printinorder ( Node* node) {
	if (node == NULL) return;
	printinorder(node->left);
	cout << node->data << " ";

	printinorder(node->right);
}
int main() {
	int post[] = {4, 2, 5, 3, 1};
	int in[] = {4, 2, 1, 5, 3};
	//start and end is the starting and ending index
	//of inorder array

	Node* root = buildtree(post, in, 0, 4);
	printinorder(root);
}
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
Node* buildtree (int pre[], int in[], int start, int end) {
	static int ind = 0;
	if (start > end) return NULL;
	int curr = pre[ind];
	ind++;
	Node* node = new Node(curr);
	if (start == end ) return node;
	int pos = search(start, end, in, curr);
	node->left = buildtree(pre, in, start, pos - 1);
	node->right = buildtree(pre, in, pos + 1, end);

	return node;
}
void printinorder ( Node* node) {
	if (node == NULL) return;
	printinorder(node->left);
	cout << node->data << " ";

	printinorder(node->right);
}
int main() {
	int pre[] = {1, 2, 4, 3, 5};
	int in[] = {4, 2, 1, 5, 3};
	//start and end is the starting and ending index
	//of inorder array
	Node* root = buildtree(pre, in, 0, 4);
	printinorder(root);
}
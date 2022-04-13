// The trick is to set a range {min .. max} for every node.
// Initialize the range as {INT_MIN .. INT_MAX}. The first node
// will definitely be in range, so create a root node.
// To construct the left subtree, set the range
// as {INT_MIN …root->data}. If a value is in the range
// {INT_MIN .. root->data}, the values are part of the
// left subtree. To construct the right subtree, set the
// range as {root->data..max .. INT_MAX}.
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
	Node() {

	}
};
void printpreorder ( Node* node) {
	if (node == NULL) return;
	cout << node->data << " ";

	printpreorder(node->left);

	printpreorder(node->right);
}

Node* newnode(int data)
{
	Node* temp = new Node();

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

// A recursive function to construct
// BST from pre[]. preIndex is used
// to keep track of index in pre[].
Node* constructTreeUtil(int pre[], int* preIndex, int key,
                        int min, int max, int size)
{
	// Base case
	if (*preIndex >= size)
		return NULL;

	Node* root = NULL;

	// If current element of pre[] is in range, then
	// only it is part of current subtree
	if (key > min && key < max) {
		// Allocate memory for root of this
		// subtree and increment *preIndex
		root = newnode(key);
		*preIndex = *preIndex + 1;

		if (*preIndex < size) {
			// Construct the subtree under root
			// All Nodes which are in range
			// {min .. key} will go in left
			// subtree, and first such Node
			// will be root of left subtree.
			root->left = constructTreeUtil(pre, preIndex,
			                               pre[*preIndex],
			                               min, key, size);
		}
		if (*preIndex < size) {
			// All Nodes which are in range
			// {key..max} will go in right
			// subtree, and first such Node
			// will be root of right subtree.
			root->right = constructTreeUtil(pre, preIndex,
			                                pre[*preIndex],
			                                key, max, size);
		}
	}

	return root;
}

int main() {
	int preorder[] = {10, 5, 1, 7, 40, 50};
	int n = 6;
	int preind = 0;
	Node * root = constructTreeUtil(preorder, &preind, preorder[0], INT_MIN, INT_MAX, n);
	printpreorder(root);
	cout << endl;

}
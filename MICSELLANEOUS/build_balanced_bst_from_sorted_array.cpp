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
//the approach is similar to binary search
Node* buildarraytobst(int arr[], int start , int end) {
	if (start > end) return NULL;
	int mid = (start + end ) / 2;
	Node* root = new Node(arr[mid]);
	root->left = buildarraytobst(arr, start, mid - 1);
	root->right = buildarraytobst(arr, mid + 1, end);

	return root;
}
int main() {
	// note this array is sorted
	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	Node* root = buildarraytobst(arr, 0, 6 );

	inorder(root);
}
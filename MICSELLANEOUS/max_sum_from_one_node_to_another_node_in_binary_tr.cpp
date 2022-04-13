
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
int ans = INT_MIN;
int maxpathsum(Node* node) {
	if (node == NULL) return 0;
	int lsum = maxpathsum(node->left);
	int rsum = maxpathsum(node->right);
	int greater = max(max(lsum + node->data, rsum + node->data), max(node->data, node->data + lsum + rsum));

	ans = max(greater, ans);
	int returnval = max(node->data, max(node->data + lsum, node->data + rsum));
	return returnval;


}

int main() {
	Node* root = new Node(1);
	root-> left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	//    1
	//   / \
	//  2   3
	// / \
	//4   5

	// inorder(root);
	maxpathsum(root);
	cout << ans;
}
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
int height (Node* node) {
	if (node == NULL) return 0;
	return max(height(node->left) , height(node->right)) + 1;
}
bool isBalanced(Node* node) {
	if (node == NULL) return true;
	int lb = isBalanced(node->left);
	int rb = isBalanced(node->right);
	if (lb == false or rb == false) return false;
	int lh = height(node->left);
	int rh = height(node->right);
	if (abs(lh - rh) > 1) return false;
	return true;
}
void printlevelorder( Node* root) {
	if (root == NULL) return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int n = q.size();
		for (int i = 0;  i < n; i++) {
			Node* curr = q.front();
			cout << curr->data << " ";
			q.pop();
			if (curr->left) q.push(curr->left);
			if (curr->right) q.push(curr->right);
		} cout << endl;
	}
}
int main() {
	Node* root = new Node(1);
	root-> left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	cout << "level order traversal of tree: " << endl;

	printlevelorder(root);
	cout << "is height balanced: ";
	cout << isBalanced(root);


}
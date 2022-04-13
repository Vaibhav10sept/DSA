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
void leftview (Node* node) {
	if (node == NULL) return;
	queue<Node*> q;
	q.push(node);
	while (!q.empty()) {
		int n = q.size();
		for (int i = 0; i < n; i++) {
			Node* curr = q.front();
			q.pop();
			if (i == 0) cout << curr->data << " ";
			if (curr->left) q.push(curr->left);
			if (curr->right) q.push(curr->right);

		}
	}
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
	cout << "left view is: " << endl;
	leftview(root);


}
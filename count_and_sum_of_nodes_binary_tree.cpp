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
int countsnodes(Node* node) {
	if (node == NULL) return 0;
	return countsnodes(node->left) + countsnodes(node->right) + 1;
}
int sumnodes(Node* node) {
	if (node == NULL) return 0;

	return sumnodes(node->left) + sumnodes(node->right) + node->data;
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
	cout << "nodes count " << countsnodes(root) << endl;
	cout << "sum of nodes " << sumnodes(root) << endl;

}
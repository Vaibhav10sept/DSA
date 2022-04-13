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
int sumreplacement(Node* node) {
	if (node == NULL) return 0;
	int lsum = sumreplacement(node->left);
	int rsum = sumreplacement(node->right);
	node->data = lsum + rsum + node->data;
	return node->data;
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
	sumreplacement(root);
	cout << "after sum replacement" << endl;
	printlevelorder(root);

}
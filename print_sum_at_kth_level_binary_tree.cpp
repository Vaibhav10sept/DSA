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
int sum = 0;
void fun ( Node* node, int level, int k) {
	if (node == NULL) return;
	if (level == k) sum += node->data;
	fun(node->left, level + 1, k);
	fun(node->right, level + 1, k);

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
	int k = 2;
	cout << "the sum at kth level is: " << endl;
	fun(root, 0, k);
	cout << sum;
}
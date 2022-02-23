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
bool find(Node* node, int val, vector<int> &ans) {
	if (node == NULL) return false;
	if (node->data == val) {
		ans.push_back(node->data);

		return true;
	}
	if (find(node->left, val, ans)) {
		ans.push_back(node->data);
		return true;
	}
	if (find(node->right, val, ans)) {
		ans.push_back(node->data);
		return true;
	}
	return false;

}
void lca (vector<int> path1, vector<int> path2) {
	int i = 0;
	int j = 0;
	while (i < path1.size() and j < path2.size() ) {
		if (path1[i] == path2[j]) break;
		i++;
		j++;
	}
	cout << path2[j];
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
	std::vector<int> path1;
	std::vector<int> path2;

	find(root, 5, path1);
	find(root, 4, path2);
	cout << "node to root path is: " << endl;
	lca(path1, path2);

}
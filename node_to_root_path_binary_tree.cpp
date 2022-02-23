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
std::vector<int> ans;
bool find(Node* node, int val) {
	if (node == NULL) return false;
	if (node->data == val) {
		ans.push_back(node->data);

		return true;
	}
	if (find(node->left, val)) {
		ans.push_back(node->data);
		return true;
	}
	if (find(node->right, val)) {
		ans.push_back(node->data);
		return true;
	}
	return false;

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
	find(root, 5);

	cout << "node to root path is: " << endl;
	for (auto i : ans)cout << i << endl;
}
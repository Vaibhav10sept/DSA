// There are two types of nodes to be considered.
// 1) Nodes in the subtree rooted with target node.
//  For example if the target node is 8
//  and k is 2, then such nodes are 10 and 14.
// 2) Other nodes, may be an ancestor of target,
// or a node in some other subtree. For target node 8
//  and k is 2, the node 22 comes in this category.

//pepcoding
//using two before codes
// 1) node to root path
// 2) print k level down
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
std::vector<Node*> path;
bool find(Node* node, int val) {
	if (node == NULL) return false;
	if (node->data == val) {
		path.push_back(node);

		return true;
	}
	if (find(node->left, val)) {
		path.push_back(node);
		return true;
	}
	if (find(node->right, val)) {
		path.push_back(node);
		return true;
	}
	return false;

}
void printklevelsdown(Node* node, int k, Node* blocker) {
	if (k < 0 or node == NULL or node == blocker) return;
	if (k == 0) cout << node->data << endl;
	printklevelsdown(node->left, k - 1, blocker);
	printklevelsdown(node->right, k - 1, blocker);
}
void printklevelsfar (Node* node, int data, int k) {
	find(node, data);
	for (int i = 0; i < path.size(); i++) {
		printklevelsdown(path[i], k - i, i == 0 ? NULL : path[i - 1]);
	}
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
	printklevelsfar(root, 2, 1);
}
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
struct bstpair {
	bool isbst;
	int min;
	int max;
	bstpair() {
		min = INT_MAX;
		max = INT_MIN;
		isbst = true;
	}
};

void inorder ( Node* node) {
	if (node == NULL) return;
	inorder(node->left);
	cout << node->data << " ";

	inorder(node->right);
}
bstpair isbst(Node* node) {
	if (node == NULL) {
		bstpair bp;
		return bp;
	}
	bstpair lp = isbst(node->left);
	bstpair rp = isbst(node->right);

	bstpair mp;

	mp.min = min(min(lp.min, rp.min), node->data);
	mp.max = max(max(lp.max, rp.max), node->data);
	mp.isbst = node->data > lp.max and node->data < rp.min and lp.isbst and rp.isbst;

	return mp;



}
int main() {
	Node* root = new Node(1);
	root-> left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	inorder(root);
	cout << endl;
	bstpair res = isbst(root);
	cout << res.isbst;
}
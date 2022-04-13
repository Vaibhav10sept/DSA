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
	Node* root;
	int size;
	bstpair() {
		size = 0;
		root = NULL;
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
	if (mp.isbst) {
		mp.root = node;
		mp.size = lp.size + rp.size + 1;

	}
	else if (lp.size > rp.size) {
		mp.root = lp.root;
		mp.size = lp.size;
	}
	else {
		mp.root = rp.root;
		mp.size = rp.size;
	}


	return mp;


}
int main() {
	Node* root = new Node(3);
	root-> left = new Node(5);
	root->right = new Node(15);
	root->left->left = new Node(4);
	root->left->right = new Node(7);
	inorder(root);
	cout << endl;
	bstpair res = isbst(root);
	cout << "size: " << res.size << endl;
	cout << "root: " << res.root->data << endl;

}
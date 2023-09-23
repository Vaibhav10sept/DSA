#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	Node(int data, Node* left, Node* right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}

	Node() {
		left = NULL;
		right = NULL;
	}
};

Node* constructBSTFromSortedArray(vector<int> arr, int low, int high) {
	if (low > high) return NULL;
	int mid = (low + high) / 2;

	Node* leftChild = constructBSTFromSortedArray(arr, low, mid - 1);
	Node* rightChild = constructBSTFromSortedArray(arr, mid + 1, high);

	Node* newNode = new Node(arr[mid], leftChild, rightChild);

	return newNode;

}

int size(Node* node) {
	if (node == NULL) return 0;

	int ans = 0;
	ans += size(node->left);
	ans += size(node->right);

	ans++;
	return ans;
}

void display(Node* node) {
	if (node == NULL) return;
	string str = "";
	str += node->left ? to_string(node->left->data) : "." ;
	str += " <- " + to_string(node->data) + " -> ";
	str += node->right ? to_string(node->right->data) : "." ;
	cout << str << endl;
	display(node->left);
	display(node->right);
}

bool nodeToRootPath(Node* node, int data, vector<int> &ans) {
	if (node == NULL) {
		return false;
	}
	if (data > node->data) {
		bool rres = nodeToRootPath(node->right, data, ans);
		if (rres) {
			ans.push_back(node->data);
			return true;
		}
	}
	else if (data < node->data) {
		bool lres = nodeToRootPath(node->left, data , ans);
		if (lres) {
			ans.push_back(node->data);
			return true;
		}
	}
	else { //found
		ans.push_back(node->data);
		return true;
	}
}

int lowestCommonAncestor(Node* root, int val1, int val2) {
	if ((root -> data > val1) && (root -> data > val2)) {
		return lowestCommonAncestor(root -> left, val1, val2);
	}
	if ((root -> data < val1) && (root -> data < val2)) {
		return lowestCommonAncestor(root -> right, val1, val2);
	}
	return root -> data;
}

int main()
{
	vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
	Node* root = constructBSTFromSortedArray(arr, 0, arr.size() - 1);
	display(root);
	cout << "lowest common ancestor: " << lowestCommonAncestor(root, 62, 87);
}
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

void replaceSumOfLarger(Node* node) {
	static int sum = 0;
	if (node == NULL) {
		return;
	}
	replaceSumOfLarger(node->right);

	//inorder phase of recursion
	int currVal = node->data;
	node->data = sum;
	sum += currVal;

	replaceSumOfLarger(node->left);

}

int main()
{
	//**********************
	//logic: inorder traversal(left,node,right) of BST give elements in increasing order
	//so, reverse inorder traversal(right,node,left) gives element in decreasing order
	//this is how we are traversing here(in reverse inorder fashion).
	//*************************
	vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
	Node* root = constructBSTFromSortedArray(arr, 0, arr.size() - 1);
	display(root);
	replaceSumOfLarger(root);
	cout << "after replacement" << endl;
	display(root);
}
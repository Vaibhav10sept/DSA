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

void printInRangeSirApproach(Node* node, int d1, int d2) {
	if (node == NULL) return;



	if (node->data < d1 and node->data < d2) {
		//move left
		// cout << "left " << node->data << endl;
		printInRangeSirApproach(node->left, d1, d2);
	}

	else if (node->data >= d1 and node->data <= d2) {
		//move right
		// cout << "right " << node->data << endl;
		printInRangeSirApproach(node->left, d1, d2);
		// if (node->data >= d1 and node->data <= d2) {
		cout << node->data << endl;
		// }
		printInRangeSirApproach(node->right, d1, d2);
	}

	else {
		//ek chota hai  or doosra bada hai
		//means move both sides
		// cout << "found " << node->data << endl;

		printInRangeSirApproach(node->right, d1, d2);


	}

}

void printInRange(Node*root, int lo, int hi)
{
	if (root == NULL)
		return;
	// cout << "test " << root->data << endl;
	if (root->data > lo)
		printInRange(root->left, lo , hi);
	if (root->data >= lo && root->data <= hi)
		cout << root->data << " ";
	if (root->data < hi)
		printInRange(root->right, lo , hi);
}

int main()
{
	vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
	Node* root = constructBSTFromSortedArray(arr, 0, arr.size() - 1);
	display(root);
	cout << "result" << endl;
	printInRange(root, 50, 87);
}
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

Node* utilMaxNode(Node* node) {
	if (node->right == NULL) return node;

	utilMaxNode(node->right);
}

Node* removeNode(Node* node, int data) {
	if (node == NULL) return NULL; // this happen if we "data" in not there in the tree.

	if (node->data < data) {
		node->right = removeNode(node->right, data);
	}
	else if (node->data > data) {
		node->left = removeNode(node->left, data);
	}
	else { //node found
		//so there are 4 cases as mentioned below:

		//case 1. the node that we are gonna remove have no child
		if (node->left == NULL and node->right == NULL) {
			return NULL;
		}
		//case 2. the node that we are gonna remove have only left child
		else if (node->left != NULL and node->right == NULL) {
			return node->left;
		}
		//case 3. the node that we are gonna remove have only right child
		else if (node->left == NULL and node->right != NULL) {
			return node->right;
		}
		//case 4. the node that we are gonna remove have both childs
		//here, we swap left side ke max with the given node and then delete
		//left ke max by calling "removeNode" function recursively.
		else {
			//getting max "Node*" from the left(left ka max nikal rhe hai)
			Node* leftMax = utilMaxNode(node->left);
			node->data = leftMax->data;
			node->left = removeNode(node->left, leftMax->data);
		}
	}

	return node;
}

int main()
{
	//*********************************
	//LOGIC: 4 cases hoge
	//case 1. the node that we are gonna remove have no child
	//case 2. the node that we are gonna remove have left child
	//case 3. the node that we are gonna remove have right child
	//case 4. the node that we are gonna remove have both childs
	vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
	Node* root = constructBSTFromSortedArray(arr, 0, arr.size() - 1);
	display(root);
	root = removeNode(root, 50);
	cout << "after removing node" << endl;
	display(root);
}
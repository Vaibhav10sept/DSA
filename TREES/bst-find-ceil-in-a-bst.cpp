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

void helperRecursive(Node* node, int key, int &ceil) {
	// i write this myself
	if (node == NULL) return;

	if (node->data == key) {
		ceil = node->data;
		return;
	}

	else if (node->data > key) { //valid candidate for ceil
		ceil = node->data;
		//move left coz hme bde me sbse chota chahiye and in bst chota left me hota h.
		helperRecursive(node->left, key, ceil);

	}
	else if (node->data < key) {
		//move left
		helperRecursive(node->right, key , ceil);
	}
}

int findCeil(Node* node, int key) {
	int ceil = -1;
	helperRecursive(node, key, ceil);
	return ceil;
}


int main()
{
	/*
	NOTE: I write this myself
	QUESTION: https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
	VIDEO:
	*/
	vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
	Node* root = constructBSTFromSortedArray(arr, 0, arr.size() - 1);
	int key = 64;
	cout << findCeil(root, key);
}
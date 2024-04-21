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

void helperRecursive(Node* node, int key, int &floor) {
	// i write this myself
	if (node == NULL) return;

	if (node->data == key) {
		floor = node->data;
		return;
	}

	else if (node->data < key) { //valid candidate for floor
		floor = node->data;
		//move right coz hme chote me sbse bda chahiye and in bst bda right me hota h.
		helperRecursive(node->right, key, floor);

	}
	else if (node->data > key) {
		//move left
		helperRecursive(node->left, key , floor);
	}
}

int findFloor(Node* node, int key) {
	int floor = -1;
	helperRecursive(node, key, floor);
	return floor;
}


int main()
{
	/*
	NOTE: I write this myself
	QUESTION: https://www.codingninjas.com/codestudio/problems/920457?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
	VIDEO: https://www.youtube.com/watch?v=xm_W1ub-K-w&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=44
	*/
	vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
	Node* root = constructBSTFromSortedArray(arr, 0, arr.size() - 1);
	int key = 64;
	cout << findFloor(root, key);
}
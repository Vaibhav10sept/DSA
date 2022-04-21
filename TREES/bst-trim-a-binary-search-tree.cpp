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

class UtilPair {
public:
	Node* node;
	int state;

	UtilPair(Node* node, int state) {
		this->node = node;
		this->state = state;
	}
	UtilPair() {

	}
};

Node* construct(vector<int> arr) {
	// state = 1 means left me node add krna hai
	// state = 2 means right me node add krna hai
	// state = 3 means stack se node ko pop krna hai
	stack<UtilPair> st;
	Node* root = new Node(arr[0]);
	UtilPair newPair(root, 1);
	st.push(newPair);

	int i = 0;
	while (!st.empty()) {
		UtilPair top = st.top();
		// cout << "top " << top.node->data << endl;
		if (top.state == 1) {
			// means left me node add krni hai
			i++;
			st.top().state++;
			if (arr[i] != -1) {
				Node* newNode = new Node(arr[i]);
				st.top().node->left = newNode;
				UtilPair newPair(newNode, 1);
				st.push(newPair);
			}
			else {
				st.top().node->left = NULL;
			}
		}
		else if (top.state == 2) {
			// means right me node add krna hai
			i++;
			st.top().state++;
			if (arr[i] != -1) {
				Node* newNode = new Node(arr[i]);
				st.top().node->right = newNode;
				UtilPair newPair(newNode, 1);
				st.push(newPair);
			}
			else {
				st.top().node->right = NULL;
			}
		}
		else {
			// means stack se node ko pop krna hai
			st.pop();
		}
	}
	return root;

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

Node* trimBST(Node* node, int low, int high) {
	/*
	LOGIC:
	If the root->val is lower than the range, then return the
	right node because all nodes to the right are higher.

	If the root->val is higher than the range, then return
	the left node because all nodes to the left are lower.

	then recurse on node->left and node->right.
	*/
	if (node == NULL) return NULL;

	if (node->data < low) {
		return trimBST(node->right, low, high);
	}
	if (node->data > high) {
		return trimBST(node->left, low, high);
	}

	//else the node->data is in range. Do simple call for left and right.
	node->left = trimBST(node->left, low, high);
	node->right = trimBST(node->right, low, high);

	return node;
}

int main()
{
	/*
	LOGIC:
	If the root->val is lower than the range, then return the
	right node because all nodes to the right are higher.

	If the root->val is higher than the range, then return
	the left node because all nodes to the left are lower.

	then recurse on node->left and node->right.
	*/
	// vector<int> arr = {3, 0, 4, -1, 2, -1, -1, 1}; //required
	vector<int> arr = {3, 0, -1, 2, 1, -1, -1, -1, 4, -1, -1};
	// vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
	int low = 1;
	int high = 3;
	Node* root = construct(arr);
	display(root);
	cout << "after trimming" << endl;
	root = trimBST(root, low, high);
	display(root);
}
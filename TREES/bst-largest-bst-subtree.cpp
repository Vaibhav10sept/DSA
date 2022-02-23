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
		data = 0;
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

class UtilPairBST {
public:
	int min;
	int max;
	int sum;
	bool isBST;

	UtilPairBST() {
		min = INT_MAX;
		max = INT_MIN;
		sum = 0;
		isBST = true;
	}
};

UtilPairBST largestBSTSubtree(Node* node, string &ans, int &maxSum) {
	if (node == NULL) {
		UtilPairBST bc;
		return bc;
	}

	UtilPairBST leftAns = largestBSTSubtree(node->left, ans, maxSum);
	UtilPairBST rightAns = largestBSTSubtree(node->right, ans, maxSum);

	UtilPairBST myAns;
	myAns.min = std::min(node->data, std::min(leftAns.min, rightAns.min));
	myAns.max = std::max(node->data, std::max(leftAns.max, rightAns.max));

	myAns.isBST = (node->data >= leftAns.max && node->data <= rightAns.min
	               && leftAns.isBST && rightAns.isBST);

	myAns.sum = leftAns.sum + rightAns.sum + node->data;
	// cout << "sum " << node->data << " " << myAns.isBST << " " << myAns.sum << endl;

	if (myAns.isBST && myAns.sum > maxSum) {
		maxSum = myAns.sum;
		ans = to_string(node->data) + " @ " + to_string(myAns.sum);
	}
	return myAns;
}

int main()
{
	//NOTE: THIS QUESTION IS THE EXTENSION OF bst-is-a-binary-search-tree
	vector<int> arr = {50, 45, 20, -1, -1, 47, -1, -1, 25, 62, -1, -1, 87, -1, -1};
	// vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};

	Node* root = construct(arr);
	display(root);

	string ans;
	int maxSum = INT_MIN;
	largestBSTSubtree(root, ans, maxSum);
	cout << "result: " << ans << endl;


}
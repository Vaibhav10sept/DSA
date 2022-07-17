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

Node* constructorForLeetcode(vector<int> arr) {
	// state = 1 means left me node add krna hai
	// state = 2 means right me node add krna hai
	// state = 3 means stack se node ko pop krna hai
	queue<UtilPair> q;
	Node* root = new Node(arr[0]);
	UtilPair newPair(root, 1);
	q.push(newPair);

	int i = 1;
	while (!q.empty() and i < arr.size()) {
		UtilPair front = q.front();

		if (front.state == 1) {
			// means left me node add krni hai
			q.front().state++;
			if (arr[i] != -1) {
				Node* newNode = new Node(arr[i]);
				q.front().node->left = newNode;
				UtilPair newPair(newNode, 1);
				q.push(newPair);
			}
			else {
				q.front().node->left = NULL;
			}
			i++;
		}
		else if (front.state == 2) {
			// means right me node add krna hai
			q.front().state++;
			if (arr[i] != -1) {
				Node* newNode = new Node(arr[i]);
				q.front().node->right = newNode;
				UtilPair newPair(newNode, 1);
				q.push(newPair);
			}
			else {
				q.front().node->right = NULL;
			}
			i++;
		}
		else {
			// state = 3 --> means queue se node ko pop krna hai
			q.pop();
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

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

class UtilClass {
public:
	int leafToLeafMaxSum;
	int nodeToLeafMaxSum;
	UtilClass() {
		leafToLeafMaxSum = INT_MIN;
		nodeToLeafMaxSum = INT_MIN;
	}
	UtilClass(int leafToLeafMaxSum, int nodeToLeafMaxSum) {
		this->leafToLeafMaxSum = leafToLeafMaxSum;
		this->nodeToLeafMaxSum = nodeToLeafMaxSum;
	}
};

UtilClass maxPathSumBwtTwoNodesHelper(Node* node) {
	UtilClass myAns;
	if (node == NULL) return myAns;
	if (node->left == NULL and node->right == NULL) { //leaf node
		myAns.nodeToLeafMaxSum = node->data;
		return myAns;
	}
	//BC ends

	UtilClass leftInfo = maxPathSumBwtTwoNodesHelper(node->left);
	UtilClass rightInfo = maxPathSumBwtTwoNodesHelper(node->right);

	myAns.leafToLeafMaxSum = max(leftInfo.leafToLeafMaxSum, rightInfo.leafToLeafMaxSum);

	if (node->left != NULL and node->right != NULL) {
		//coz, agr tumhare dono child hoge tbhi tum apne se hote hue leaf to leaf path bna paoge(think, watch video)
		myAns.leafToLeafMaxSum = max(myAns.leafToLeafMaxSum, leftInfo.nodeToLeafMaxSum + node->data + rightInfo.nodeToLeafMaxSum);

	}

	myAns.nodeToLeafMaxSum = max(leftInfo.nodeToLeafMaxSum, rightInfo.nodeToLeafMaxSum) + node->data;
	return myAns;
}

int maxPathSumBwtTwoNodes(Node* root) {
	UtilClass res = maxPathSumBwtTwoNodesHelper(root);
	return res.leafToLeafMaxSum;
}

int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=kSSAdqB7qsw&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=55
	LEETCODE:
	*/
	Node *root = newNode(-15);
	root->left = newNode(5);
	root->right = newNode(6);
	root->left->left = newNode(-8);
	root->left->right = newNode(1);
	root->left->left->left = newNode(2);
	root->left->left->right = newNode(6);
	root->right->left = newNode(3);
	root->right->right = newNode(9);
	root->right->right->right = newNode(0);
	root->right->right->right->left = newNode(4);
	root->right->right->right->right = newNode(-1);
	root->right->right->right->right->left = newNode(10);

	display(root);
	cout << "res" << endl;
	cout << maxPathSumBwtTwoNodes(root);
}
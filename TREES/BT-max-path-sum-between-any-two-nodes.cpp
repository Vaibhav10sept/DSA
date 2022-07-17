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
	int nodeToNodeMaxSum;
	int rootToNodeMaxSum;
	UtilClass() {
		nodeToNodeMaxSum = INT_MIN;
		rootToNodeMaxSum = 0; //think, watch video
	}
	UtilClass(int nodeToNodeMaxSum, int rootToNodeMaxSum) {
		this->nodeToNodeMaxSum = nodeToNodeMaxSum;
		this->rootToNodeMaxSum = rootToNodeMaxSum;
	}
};

int getMaxSum(int first, int second, int third, int four, int five) {
	int maxSum = INT_MIN;

	vector<int> arr = {first, second, third, four, five};
	for (auto ele : arr) {
		maxSum = max(maxSum, ele);
	}
	return maxSum;
}

UtilClass maxPathSumBwtTwoNodesHelper(Node* node) {
	UtilClass myAns;
	if (node == NULL) return myAns;
	//BC ends

	UtilClass leftInfo = maxPathSumBwtTwoNodesHelper(node->left);
	UtilClass rightInfo = maxPathSumBwtTwoNodesHelper(node->right);

	int rootToNodeMaxSum = max(leftInfo.rootToNodeMaxSum, rightInfo.rootToNodeMaxSum) + node->data;

	//there can be various possible please read all possibiliy in the below code
	int nodeToNodeMaxSum = getMaxSum(leftInfo.nodeToNodeMaxSum, rightInfo.nodeToNodeMaxSum,
	                                 leftInfo.rootToNodeMaxSum + node->data + rightInfo.rootToNodeMaxSum, node->data, rootToNodeMaxSum);

	myAns.rootToNodeMaxSum = max(rootToNodeMaxSum, node->data);
	myAns.nodeToNodeMaxSum = nodeToNodeMaxSum;
	return myAns;
}

int maxPathSumBwtTwoNodes(Node* root) {
	UtilClass res = maxPathSumBwtTwoNodesHelper(root);
	return res.nodeToNodeMaxSum;
}

int main()
{
	/*
	PREREQUISITE: max path sum between two leafs
	VIDEO LINK: https://www.youtube.com/watch?v=ElKcXGkYldA&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=57
	LEETCODE: https://leetcode.com/problems/binary-tree-maximum-path-sum/
	*/
	// vector<int> arr = { -10, 9, 20, -1, -1, 15, 7};
	vector<int> arr = {1, 2, 3};
	Node* root = constructorForLeetcode(arr);

	display(root);
	cout << "res" << endl;
	cout << maxPathSumBwtTwoNodes(root);
}
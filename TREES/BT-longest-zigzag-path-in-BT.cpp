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

class UtilClass {
public:
	int forwardSlope;
	int backwardSlope;
	int maxLen;
	UtilClass() {
		forwardSlope = -1; //-1, coz edge ke terms me nikaal rhe hai
		backwardSlope = -1;
		maxLen = 0;
	}
};

UtilClass longestZigZagPathInBTHelper(Node* node) {
	/*
	watch video recommended
	*/
	//BASE CASES
	if (node == NULL) return UtilClass();

	//apne aap ko starting point mante hue forward, backward slope ke sath sbse bada zigzag path
	UtilClass leftInfo = longestZigZagPathInBTHelper(node->left);
	UtilClass rightInfo = longestZigZagPathInBTHelper(node->right);

	UtilClass myAns;
	//NOTE: left ke sath backslope use hoga, or right ke sath forward slope, tbhi to zigzag path bnega(think, watch video)

	//CHECK: ki left/right subtree me sbse bada zigzag path hai, ya mujhe include krke sbse bda zigzag path bn rha, vo hme myans.maxlen me store krna h
	myAns.maxLen = max(max(leftInfo.maxLen, rightInfo.maxLen), max(leftInfo.backwardSlope, rightInfo.forwardSlope) + 1);
	//mereko starting node mante hue forward slope ke sath sbse bada path
	myAns.forwardSlope = leftInfo.backwardSlope + 1;
	//mereko starting node mante hue backward slope ke sath sbse bada path
	myAns.backwardSlope = rightInfo.forwardSlope + 1;

	return myAns;
}

int longestZigZagPathInBT(Node* root) {
	UtilClass res = longestZigZagPathInBTHelper(root);
	return res.maxLen;
}

int main()
{	/*
	NOTE: postorder me sara kaam hoga.
	PREREQUISITE: return is similar to "house robbery".
	VIDEO LINK: https://www.youtube.com/watch?v=7aqHhENUbkQ&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=7
	LEETCODE LINK: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
	*/
	vector<int> arr = {1, -1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, 1, -1, 1};
	Node* root = constructorForLeetcode(arr);
	display(root);
	cout << "answer " << longestZigZagPathInBT(root);
}
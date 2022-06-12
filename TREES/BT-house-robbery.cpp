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
	int choriNaKarnePar;
	int choriKarnePar;
	UtilClass(int first, int second) {
		choriNaKarnePar = first;
		choriKarnePar = second;
	}
	UtilClass() {

	}
};

UtilClass houseRobberyHelper(Node* node) {
	/*
	watch video recommended
	LOGIC: har node 2 cheeze return krega
	1. merepe chori na krne par kitna max paesa generate hota hai
	2. merepe chori krne par kitna max paesa generate hota hai
	*/
	//BASE CASES
	if (node == NULL) return UtilClass(0, 0);

	UtilClass leftInfo = houseRobberyHelper(node->left);
	UtilClass rightInfo = houseRobberyHelper(node->right);

	UtilClass myAns;
	//agr mae chori kruga toh left or right chori nhi krege or + mera data bhi add hoga
	myAns.choriKarnePar = leftInfo.choriNaKarnePar + rightInfo.choriNaKarnePar + node->data;
	//age mae chori nhi kruga toh left or right chori kre ya na kre matter nhi krta toh ham left or right me with or without robbery ka max value lelege
	myAns.choriNaKarnePar = max(leftInfo.choriNaKarnePar, leftInfo.choriKarnePar) + max(rightInfo.choriNaKarnePar, rightInfo.choriKarnePar);

	return myAns;

}

int houseRobbery(Node* root) {
	UtilClass res = houseRobberyHelper(root);
	return max(res.choriKarnePar, res.choriNaKarnePar);
}

int main()
{	/*
	NOTE: postorder me sara kaam hoga.
	VIDEO LINK: youtube.com/watch?v=kTL5LhCTL1c&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=6
	LEETCODE LINK: https://leetcode.com/problems/house-robber-iii/
	*/
	vector<int> arr = {3, 4, 5, 1, 3, -1, 1};
	Node* root = constructorForLeetcode(arr);
	display(root);
	cout << "answer " << houseRobbery(root);
}
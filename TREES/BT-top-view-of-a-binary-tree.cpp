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
	int horizontalLevel;
	Node* node;

	UtilClass(int hl, Node* node) {
		this->node = node;
		horizontalLevel = hl;
	}

	UtilClass() {
		node = NULL;
	}
};

void widthHelper(Node* node, int horizontalLevel, int &minHorizontalLevel, int &maxHorizontalLevel) {
	//this is recursive function
	if (node == NULL) return;

	minHorizontalLevel = min(minHorizontalLevel, horizontalLevel);
	maxHorizontalLevel = max(maxHorizontalLevel, horizontalLevel);

	widthHelper(node->left, horizontalLevel - 1 , minHorizontalLevel, maxHorizontalLevel);
	widthHelper(node->right, horizontalLevel + 1 , minHorizontalLevel, maxHorizontalLevel);

}

vector<int> topView(Node* root) {
	//find the widht of the tree.
	int minHorizontalLevel = INT_MAX;
	int maxHorizontalLevel = INT_MIN;
	widthHelper(root, 0, minHorizontalLevel, maxHorizontalLevel);
	int width = maxHorizontalLevel - minHorizontalLevel + 1;

	//create vector of vector of size width
	vector<int> ans(width, INT_MIN);

	//NOTE: some part of code is similar to line wise traversal
	queue<UtilClass> q;

	q.push(UtilClass(abs(minHorizontalLevel), root)); //think(why abs(minhorizontallevel)), all logic lies here, watch video

	while (!q.empty()) {
		int size = q.size();
		//this is line wise traversal technique
		while (size--) {
			UtilClass removedObj = q.front();
			q.pop();
			Node* tempNode = removedObj.node;

			//ans vector me horizontal level ko as a index use krke push kro
			if (ans[removedObj.horizontalLevel] == INT_MIN) //agr iss index me kuch nhi h means INT_MIN h tbhi add kro other wise mt kro(to make top view)(think CS)
				//this is the only difference in bottom view and top view
				ans[removedObj.horizontalLevel] = tempNode->data;

			//queue pe left or right child add kro

			//left ke lie horizontal level "- 1" hota hai
			if (tempNode->left != NULL) q.push(UtilClass(removedObj.horizontalLevel - 1, tempNode->left));
			//right ke lie horizontal level "+ 1" hota hai
			if (tempNode->right != NULL) q.push(UtilClass(removedObj.horizontalLevel + 1, tempNode->right));
		}
	}
	return ans;
}

int main()
{
	/*
	PREREQUISITE: veritcal order traversal of BT method-2 and bottom view of BT
	VIDEO LINK: https://www.youtube.com/watch?v=kCQJTAqbExg&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=28
	*/
	vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
	Node* root = construct(arr);
	display(root);
	cout << "top view " << endl;
	vector<int> res = topView(root);
	for (int ele : res) {
		cout << ele << " ";
	}
}
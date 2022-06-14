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
	Node* parent;
	int leftBoundary;
	int rightBoundary;

	UtilClass(Node* parent, int leftBoundary, int rightBoundary) {
		this->parent = parent;
		this->leftBoundary = leftBoundary;
		this->rightBoundary = rightBoundary;
	}
	UtilClass() {
		parent = NULL;
		leftBoundary = INT_MIN;
		rightBoundary = INT_MAX;
	}
};

Node* constructBSTFromlevelorderTraversal(vector<int> levelorder) {
	queue<UtilClass> q;
	q.push(UtilClass());
	Node* root = NULL;

	int idx = 0;
	while (!q.empty() and idx < levelorder.size()) {
		UtilClass removedObj = q.front();
		q.pop();

		int val = levelorder[idx];
		if (val < removedObj.leftBoundary or val > removedObj.rightBoundary) continue;

		Node* node = new Node(val);
		idx++;

		if (removedObj.parent == NULL) root = node;
		else {
			//linking
			Node* parent = removedObj.parent;
			if (val <= parent->data) parent->left = node;
			else parent->right = node;
		}

		//add krna new node ke potential left and right child in queue.
		q.push(UtilClass(node, removedObj.leftBoundary, node->data)); //left child
		q.push(UtilClass(node, node->data, removedObj.rightBoundary)); //right child
	}
	return root;
}

int main()
{
	/*
	NOTE: we are using queue here.
	PREREQUISITE: construct BST from preorder traversal and construct bst from postorder traversal
	VIDEO LINK: https://www.youtube.com/watch?v=8w_NSKo9e74&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=19
	*/
	vector<int> levelorder = {7, 4, 12, 3, 6, 8, 1, 5, 10};
	Node* root = constructBSTFromlevelorderTraversal(levelorder);
	display(root);
}
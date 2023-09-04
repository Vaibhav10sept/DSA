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

Node* getRightMostNode(Node* leftNode, Node* curr) {
	while (leftNode->right != NULL and leftNode->right != curr) {
		leftNode = leftNode->right;
	}
	return leftNode;
}

void morrisInorderTraversal(Node* root) {
	//WV recommended
	Node* curr = root;
	while (curr) {
		Node* leftNode = curr->left;
		if (leftNode == NULL) {
			//inorder print
			cout << curr->data << " ";
			curr = curr->right;
		}
		else { //leftNode != NULL
			Node* rightMostNode = getRightMostNode(leftNode, curr);
			if (rightMostNode->right == curr) { //means thread already exist and we need to break the thread and make right as NULL
				//also this means that left subtree is traversed so we can print in inorder fashion
				rightMostNode->right = NULL;
				cout << curr->data << " ";
				curr = curr->right;
			}
			else { //means rightMostNode->right == NULL
				//so we need to create the thread
				rightMostNode->right = curr;
				curr = leftNode;
			}
		}
	}
}

int main()
{
	/*
	NOTE: sara smjh me aa gya ek baar video dekh lena sb clear ho jaega
	WV recommeneded
	VIDOE: https://www.youtube.com/watch?v=oz17ihxBxgU&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=1
	QUESTION: https://takeuforward.org/data-structure/morris-inorder-traversal-of-a-binary-tree/
	*/
	vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
	Node* root = construct(arr);
	morrisInorderTraversal(root);
}
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

class utilPair {
public:
	Node* node;
	int state;
	// state = 1 means preorder
	// state = 2 means inorder
	// state = 3 means postorder
	utilPair(Node* node, int state) {
		this->node = node;
		this->state = state;
	}

};

void iterativeTraversal(Node* node) {
	string pre = "";
	string post = "";
	string in = "";

	stack<UtilPair> st;
	UtilPair newPair(node, 1);
	st.push(newPair);
	while (!st.empty()) {
		UtilPair temp = st.top();
		if (temp.state == 1) {
			// preorder
			pre += to_string(temp.node->data) + " ";

			st.top().state++;

			if (temp.node->left) {
				UtilPair newPair(temp.node->left, 1);
				st.push(newPair);
			}

		}
		else if (temp.state == 2) {
			//inorder
			in += to_string(temp.node->data) + " ";

			st.top().state++;

			if (temp.node->right) {
				UtilPair newPair(temp.node->right, 1);
				st.push(newPair);
			}
		}
		else  {
			//postorder
			post += to_string(temp.node->data) + " ";
			st.pop();
		}
	}
	cout << "preorder " << pre << endl;
	cout << "postorder " << post << endl;
	cout << "inorder " << in << endl;
}

int main()
{
	vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
	Node* root = construct(arr);
	// display(root);
	iterativeTraversal(root);
}
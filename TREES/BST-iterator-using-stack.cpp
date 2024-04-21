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

Node* constructBSTFromSortedArray(vector<int> arr, int low, int high) {
	if (low > high) return NULL;

	int mid = (low + high) / 2;

	Node* leftChild = constructBSTFromSortedArray(arr, low, mid - 1);
	Node* rightChild = constructBSTFromSortedArray(arr, mid + 1, high);

	Node* newNode = new Node(arr[mid], leftChild, rightChild);

	return newNode;
}

int size(Node* node) {
	if (node == NULL) return 0;

	int ans = 0;
	ans += size(node->left);
	ans += size(node->right);

	ans++;
	return ans;
}

class UtilPair {
public:
	Node* node;
	int state;

	UtilPair(Node* node, int state) {
		this->node = node;
		this->state = state;
	}
};

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

class BSTIterator {
private:
	stack<Node*> st;
public:
	BSTIterator(Node* root) {
		push_in_stack(root);
	}

	void push_in_stack(Node* root) {
		while (root) {
			st.push(root);
			root = root->left;
		}
	}

	int next() {
		Node* top = st.top(); st.pop();
		push_in_stack(top->right);
		return top->data;
	}

	bool hasNext() {
		return st.empty();
	}
};

int main()
{
	/*
	LEETCODE: https://leetcode.com/problems/binary-search-tree-iterator/
	VIDEO LINK: https://www.youtube.com/watch?v=irozX_OvmKI&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=39
	*/
	vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
	Node* root = constructBSTFromSortedArray(arr, 0, arr.size() - 1);
	display(root);
	cout << "res" << endl;
	BSTIterator obj(root);
	while (obj.hasNext()) {
		cout << obj.next() << " ";
	}

}
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

void addAllLeft(Node* node, stack<Node*> &st) {
	while (node != NULL) {
		st.push(node);
		node = node->left;
	}
}

Node* bstToDoublyLinkedList(Node* root) {
	//watch video recommended
	stack<Node*> st;
	addAllLeft(root, st);

	Node* dummy = new Node(-1);
	Node* prev = dummy;

	//NOTE: inorder me traverse krna hai tree
	while (!st.empty()) {
		Node* curr = st.top();
		// cout << "curr " << curr->data << endl;
		st.pop();

		//creating doubly linked list links
		prev->right = curr;
		// cout << "prev " << prev->data << endl;

		curr->left = prev;
		//setting prev
		prev = curr;

		addAllLeft(curr->right, st);
	}

	Node* head = dummy->right;
	dummy->right = head->left = NULL;

	//creating circular doubly linked list
	// prev->right = head;
	// head->left = prev;

	return head;
}

printDoublyLinkedList(Node* head) {
	Node* temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->right;
	}
}


int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=C2ThnBgAF5I&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=48
	*/
	vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
	Node* root = constructBSTFromSortedArray(arr, 0, arr.size() - 1);
	display(root);
	root = bstToDoublyLinkedList(root);
	cout << "print doubly linked list" << endl;
	printDoublyLinkedList(root);
}
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

class BSTIterator {
public:
	Node* curr;
	BSTIterator(Node* root) {
		curr = root;
	}

	Node* getRightMostNode(Node* leftNode, Node* curr) {
		while (leftNode->right != NULL and leftNode->right != curr) {
			//think for, leftNode->right != curr, watch video
			leftNode = leftNode->right;
		}
		return leftNode;
	}

	Node* morrisInorderTrversal() {
		//watch video recommended.
		Node* res = NULL;
		//NOTE: curr is the member variable for class BSTIterator
		while (curr) {
			Node* leftNode = curr->left;
			if (leftNode == NULL) {
				//inorder phase
				res = curr;
				curr = curr->right;
				break; //think ki break kyo kia
			}
			else { //node.left != NULL
				//now, find the right most node.
				Node* rightMostNode = getRightMostNode(leftNode, curr);
				if (rightMostNode->right == NULL) { //create thread.
					rightMostNode->right = curr;
					curr = curr->left;
				}
				else { //rightMostNode->right != NULL, means right most node ka right curr ko point krra hoga, toh ye link break kro
					//this also means that the left subtree is processed so inorder me left subtree process krne ke baad print krte so do that
					// break the thread.
					rightMostNode->right = NULL;
					//inorder phase
					res = curr;
					//this indicates that left subtree is processed so move to right.
					curr = curr->right; //move curr to right
					break; //again break,(think)
				}
			}
		}
		return res;
	}

	int next() {
		Node* res = morrisInorderTrversal();
		return res->data;
	}

	bool hasNext() {
		return curr != NULL;
	}
};

int main()
{
	/*
	NOTE: inorder me sab kuch hoga.
	PREREQUISITE: morris traversal inorder.
	SPACE: constant.
	TIME: O(3n), coz on an average har node 3 baar visit hoti hai, watch video
	NOTE: using morris traversal means we can traverse BT without using any extra space(stack or recursive stack).
	VIDEO LINK: https://www.youtube.com/watch?v=SeYBu-dy51o&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=38
	LEETCODE LINK: https://leetcode.com/problems/binary-search-tree-iterator/
	*/
	vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
	Node* root = construct(arr);
	display(root);
	cout << "res" << endl;
	BSTIterator obj(root);
	while (obj.hasNext()) {
		cout << obj.next() << " ";
	}
}
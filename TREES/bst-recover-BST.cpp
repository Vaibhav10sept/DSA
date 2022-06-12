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

Node* firstMistake, *secondMistake, *pre;
void inorder(Node* root) {
	if (root == nullptr) return;

	inorder(root->left);

	if (firstMistake == nullptr and root->data < pre->data) {
		firstMistake = pre;
		secondMistake = root; //coz, agr consecutive node swap kie hoge, to else if kbhi hit nhi hoga(think)
	}
	else if (firstMistake != nullptr and root->data < pre->data) {
		secondMistake = root;
	}
	pre = root;

	inorder(root->right);
}

void recoverBST(Node* node) {
	//we do inorder traversal and identify the node which is affecting the sorted order, coz inorder traversal give nodes in sorted fashion
	pre = new Node(INT_MIN);
	// firstMistake = NULL;
	// secondMistake = NULL;
	inorder(node); //this will fill up firstMistake and secondMistake
	//now, swap the data of firstMistake and secondMistake.
	swap(firstMistake->data, secondMistake->data);
}

int main()
{
	//********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=ZWGW7FminDM
	// LEETCODE LINK: https://leetcode.com/problems/recover-binary-search-tree/
	//*********************************
	vector<int> arr = {1, 3, -1, -1, 2};
	Node* root = constructorForLeetcode(arr);
	display(root);
	recoverBST(root);
	cout << "after recovery" << endl;
	display(root);
}
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

class HelperClass {
public:
	Node* node;
	int idx;

	HelperClass(Node* node, int idx) {
		this->node = node;
		this->idx = idx;
	}

	HelperClass() {

	}
};

int maxWidth(Node* root) {
	/*LOGIC: agr BT array(0 indexed) me hota to kisi node ka left child-> 2*idx + 1
	and right child -> 2*idx + 2.
	yhi logic use krke ham solve krege
	watch video recommended
	*/
	queue<HelperClass> q;
	int maxWidth = 0;

	q.push(HelperClass(root, 0));
	while (!q.empty()) {
		int size = q.size(); //for line wise traversal
		int leftMostNodeIdx = q.front().idx;
		int rightMostNodeIdx = q.front().idx;

		while (size--) { //for level by level traversal
			HelperClass rightMostNode = q.front(); //thiink, watch video
			q.pop();
			int rightMostNodeIdx = rightMostNode.idx;

			maxWidth = max(maxWidth, rightMostNodeIdx - leftMostNodeIdx + 1);

			//left child ko push kro, left child ka idx --> 2*idx + 1
			if (rightMostNode.node->left != NULL) q.push(HelperClass(rightMostNode.node->left, 2 * rightMostNodeIdx + 1));

			//right child ko push kro, right child ka idx --> 2*idx + 2
			if (rightMostNode.node->right != NULL) q.push(HelperClass(rightMostNode.node->right, 2 * rightMostNodeIdx + 2));

			// cout << "rightMostNodeIdx " << rightMostNodeIdx << " " << rightMostNode.node->data << endl;
			// cout << "leftMostNodeIdx " << leftMostNodeIdx << " " << rightMostNode.node->data << endl;



		}
		// maxWidth = max(maxWidth, rightMostNodeIdx - leftMostNodeIdx + 1);
	}
	return maxWidth;
}

int main()
{
	/*
	NOTE: max width and shadow/widht of a BT is diff(WV)
	LEETCODE LINK: https://leetcode.com/problems/maximum-width-of-binary-tree/
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=R9qiY7OK9JQ
	*/
	vector<int> arr = {1, 3, 2, 5, 3, -1, 9};
	Node* root = constructorForLeetcode(arr);
	display(root);
	cout << "max width of the tree is: " << endl;
	cout << maxWidth(root) << endl;

}
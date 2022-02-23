#include <bits/stdc++.h>
using namespace std;
//********************************
// PLEASE WATCH THE GENERIC TREE LEVEL 1 PEPCODING
// YOUTUBE PLAYLIST SOME OF THE FUNCTION HERE ARE NOT
// PRESENT INSIDE THE VIDEO THAT ARE THERE IN THE FOLDER.
class Node {
public:
	int data;
	vector<Node*> children;
};

void display(Node* root) {
	string str = to_string(root->data) + " -> ";
	for (Node* child : root->children) {
		str += to_string(child->data) + ",";
	}
	str += ".";
	cout << str << endl;

	for (Node* child : root->children) {
		display(child);
	}
}

Node* construct(vector<int> arr) {
	stack<Node*> st;
	Node* root = new Node();
	root->data = arr[0];
	st.push(root);
	for (int i = 1; i < arr.size(); i++) {
		int val = arr[i];
		if (val == -1 && !st.empty()) {
			st.pop();
		}
		else {
			Node* newNode = new Node();
			newNode->data = val;
			newNode->children = {};
			st.top()->children.push_back(newNode);
			st.push(newNode);
		}
	}
	return root;
}

int size(Node* root) {
	int ans = 0;
	for (Node* child : root->children) {
		ans += size(child);
	}
	ans++;
	return ans;
}
void traversal(Node* root) {
	cout << "pre node " << root->data << endl;
	for (Node* child : root->children) {
		cout << "edge pre " << root->data << endl;
		traversal(child);
		cout << "edge post " << root->data << endl;

	}

	cout << "post node "  << root->data << endl;
}

int main()
{
	vector<int> arr  = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1
	                   };
	Node* root = construct(arr);
	traversal(root);
}
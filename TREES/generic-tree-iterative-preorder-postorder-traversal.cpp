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

class UtilPair {
public:
	Node* node;
	int state; // state will hold the index of children vector
	UtilPair(Node* node, int state) {
		this->state = state;
		this->node = node;
	}
};

void iterativePrePostTraversal(Node* root) {
	stack<UtilPair> st;
	UtilPair obj(root, -1);
	st.push(obj);

	string pre = "";
	string post = "";

	while (!st.empty()) {
		UtilPair temp = st.top();
		if (temp.state == -1) { // state will hold the index of children vector
			// print preorder
			st.pop();
			pre += to_string(temp.node->data) + " ";
			temp.state = 0;
			st.push(temp);
		}
		else if (temp.state >= 0 && temp.state < temp.node->children.size()) {
			st.top().state = temp.state + 1;
			UtilPair newEntry(temp.node->children[temp.state], -1);
			st.push(newEntry);
		}
		else {
			// print postorder and remove from stack
			post += to_string(temp.node->data) + " ";
			st.pop();
		}
	}
	cout << "Preorder " << pre << endl;
	cout << "postOrder " << post << endl;
}
int main()
{
	// vector<int> arr  = {10, 20, 50, -1, 60, -1, -1, 30,
	//                     70, -1, 80, 110, -1, 120, -1, -1,
	//                     90, -1, -1, 40, 100, -1, -1, -1
	//                    };
	vector<int> arr = {10,  20, -1, 30, 50, -1, 60, -1, -1,
	                   40, -1, -1
	                  };
	Node* root = construct(arr);
	iterativePrePostTraversal(root);
}
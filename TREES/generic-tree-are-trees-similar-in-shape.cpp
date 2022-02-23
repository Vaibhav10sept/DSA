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

bool areSimilarInShape(Node* root1, Node* root2) {
	if (root1->children.size() != root2->children.size())
		return false;
	// after this both size are same
	for (int i = 0; i < root1->children.size() ; i++) {
		if (areSimilarInShape(root1->children[i], root2->children[i]) == false) {
			return false;
		}
	}
	return true;
}

int main()
{
	// vector<int> arr  = {10, 20, 50, -1, 60, -1, -1, 30,
	//                      70, -1, 80, 110, -1, 120, -1, -1,
	//                      90, -1, -1, 40, 100, -1, -1, -1
	//                     };
	vector<int> arr = {10,  20, -1, 30, 50, -1, 60, -1, -1,
	                   40, -1, -1
	                  };
	vector<int> arr1 = {10,  20, -1, 30, 50, -1, 60, -1, -1,
	                    70, -1, -1
	                   };
	Node* root1 = construct(arr);
	Node* root2 = construct(arr1);
	cout << "are trees similar in shape " << areSimilarInShape(root1, root2) << endl;

}
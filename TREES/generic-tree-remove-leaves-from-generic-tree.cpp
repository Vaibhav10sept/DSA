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
void removeLeaves(Node* root) {
	// for (auto i = root->children.begin(); i != root->children.end(); ++i) {
	// 	if ((*i)->children.size() == 0) {
	// 		root->children.erase(i);
	// 		i--;
	// 	}
	// }

	for (auto i = root->children.begin(); i != root->children.end(); ++i) {
		if ((*i)->children.size() == 0) {
			root->children.erase(i);
			i--;
		}
	}
	for (Node* child : root->children) {
		removeLeaves(child);
	}

}
int main()
{
	// vector<int> arr  = {10, 20, 50, -1, 60, -1, -1, 30,
	//                     70, -1, 80, 110, -1, 120, -1, -1,
	//                     90, -1, -1, 40, 100, -1, -1, -1
	//                    };
	vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1,
	                   80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1 , -1, -1
	                  };
	Node* root = construct(arr);
	cout << "before removal" << endl;
	display(root);
	cout << "after removal" << endl;
	removeLeaves(root);
	display(root);

}
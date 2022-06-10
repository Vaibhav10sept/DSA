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

bool nodeToRootPath(Node* root, int data, vector<int> *ans) {
	if (root->data == data) {
		ans->push_back(root->data);
		return true;
	}
	for (Node* child : root->children) {
		bool cans = nodeToRootPath(child, data, ans);
		if (cans) {
			ans->push_back(root->data);
			return true;
		}
	}
	return false;
}

int lowestCommonAncestor(int node1, int node2, Node* root) {
	vector<int> ans = {};
	nodeToRootPath(root, node1, &ans);
	vector<int> ans2 = {};
	nodeToRootPath(root, node2, &ans2);
	int i = ans.size() - 1;
	int j = ans2.size() - 1;
	while (i >= 0 && j >= 0 && ans[i] == ans2[j]) {
		i--;
		j--;
	}
	i++;
	j++;
	return ans[i];
}

int distanceBetweenNodes(int node1, int node2, Node* root) {
	//*************************************
	// NOTE: THIS IS SIMILAR TO lowestCommonAncestor(SEE ABOVE FUNCTION)
	// ALSO WE ARE USING nodeToRootPath AS HELPER FUNCTION.
	//*******************************************
	vector<int> ans = {};
	nodeToRootPath(root, node1, &ans);
	vector<int> ans2 = {};
	nodeToRootPath(root, node2, &ans2);
	int i = ans.size() - 1;
	int j = ans2.size() - 1;
	while (i >= 0 && j >= 0 && ans[i] == ans2[j]) {
		i--;
		j--;
	}
	i++;
	j++;
	return i + j;
}

int main()
{
	vector<int> arr  = {10, 20, 50, -1, 60, -1, -1, 30,
	                    70, -1, 80, 110, -1, 120, -1, -1,
	                    90, -1, -1, 40, 100, -1, -1, -1
	                   };
	// vector<int> arr = {10,  20, -1, 30, 50, -1, 60, -1, -1,
	//                    40, -1, -1
	//                   };
	Node* root = construct(arr);

	cout << "distance between nodes: " << distanceBetweenNodes(110, 70, root) << endl;


}
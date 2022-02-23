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

void multiSolver(Node* root, int* max, int* min, int* height, int* size, int depth ) {
	if (root->data > *max) {
		*max = root->data;
	}
	if (root->data < *min) {
		*min = root->data;
	}
	(*size)++;
	*height = std::max(*height, depth);
	for (Node* child : root->children) {
		multiSolver(child, max, min, height, size, depth + 1);
	}


}

int main()
{
	//******************************
	// NOTE: MULTISOLVER WILL GIVE US HEIGHT, MAX, MIN, SIZE
	// IN A SINGLE FUNCTION.
	//**************************************
	vector<int> arr  = {10, 20, 50, -1, 60, -1, -1, 30,
	                    70, -1, 80, 110, -1, 120, -1, -1,
	                    90, -1, -1, 40, 100, -1, -1, -1
	                   };
	// vector<int> arr = {10,  20, -1, 30, 50, -1, 60, -1, -1,
	//                    40, -1, -1
	//                   };
	Node* root = construct(arr);
	int max = INT_MIN;
	int min = INT_MAX;
	int height = 0;
	int size = 0;
	multiSolver(root, &max, &min, &height, &size, 0);
	cout << max << " " << min << " " << height << " " << size << endl;
}
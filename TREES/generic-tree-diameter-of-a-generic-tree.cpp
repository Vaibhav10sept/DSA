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

int calculateDiaReturnHeight(Node* root, int* dia) {
	int dch = -1; // deepest child height
	int sdch = -1; // second deepest child height
	// -1 becoz we are calculating height in terms of edges.

	for (Node* child : root->children) {
		int ch = calculateDiaReturnHeight(child, dia);
		if (ch > dch) {
			dch = ch;
			sdch = dch;
		}
		else if (ch > sdch) {
			sdch = ch;
		}
	}
	if (sdch + dch + 2 > *dia) {
		*dia = sdch + dch + 2;
	}
	dch++; //coz, deepest child height(dch) hi height hoti hai.
	return dch;
}

int main()
{
	//********************************
	// NOTE: DIAMETER OF A TREE MEANS THE MAXIMUM DISTANCE
	// BETWEEN ANY TWO NODES IN TERMS OF EDGES
	// LOGIC: USE HEIGHTS HERE.
	// DIAMETER OF TREE = HEIGHT OF LARGEST SUBTREE +
	// HEIGHT OF SECOND LARGEST SUBTREE + 2
	// NOTE: AESA JRURI NHI KI DIAMETER ROOT NODE SE
	// HOKE GUJRE.
	//**********************************
	vector<int> arr  = {10, 20, -50, -1, 60, -1, -1, 30,
	                    70, -1, 80,  -1,
	                    90, -1, -1, 40, 100, -1, -1, -1
	                   };
	// vector<int> arr = {10,  20, -1, 30, 50, -1, 60, -1, -1,
	//                    40, -1, -1
	//                   };
	Node* root = construct(arr);
	int res;
	calculateDiaReturnHeight(root, &res);
	cout << res;
}
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

class UtilClass {
public:
	int horizontalLevel;
	Node* node;

	UtilClass(int hl, Node* node) {
		this->node = node;
		horizontalLevel = hl;
	}

	UtilClass() {
		node = NULL;
	}
};

vector<vector<int>> verticalOrderTraversal(Node* root) {
	//NOTE: some part of code is similar to line wise traversal
	queue<UtilClass> q;
	map<int, vector<int>> mp;
	//mp.first --> horizontal level
	//mp.second --> vector of all the root->data for that horizontal level
	q.push(UtilClass(0, root));

	while (!q.empty()) {
		int size = q.size();
		//this is line wise traversal technique
		while (size--) {
			UtilClass removedObj = q.front();
			q.pop();
			Node* tempNode = removedObj.node;

			//map ka kaam kro
			mp[removedObj.horizontalLevel].push_back(tempNode->data);

			//queue pe left or right child add kro
			if (tempNode->left != NULL) q.push(UtilClass(removedObj.horizontalLevel - 1, tempNode->left));
			if (tempNode->right != NULL) q.push(UtilClass(removedObj.horizontalLevel + 1, tempNode->right));
		}
	}

	vector<vector<int>> ans;
	for (auto it : mp) {
		ans.push_back(it.second);
	}
	return ans;
}

int main()
{
	/*
	NOTE: here are using map and queue(queue for the line wise traversal)
	PREREQUISITE: line wise traversal of BT
	NOTE: we use map here.
	VIDEO LINK: https://www.youtube.com/watch?v=LscPXvD1N1A&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=25
	*/
	vector<int> arr = {1, 2, 3, 4, 6, 5, 7};
	Node* root = constructorForLeetcode(arr);
	display(root);
	cout << "res " << endl;
	vector<vector<int>> res = verticalOrderTraversal(root);
	for (vector<int> vec : res) {
		for (int ele : vec) cout << ele << " ";
		cout << endl;
	}
}
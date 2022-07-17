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
	Node* node;
	int state;

	UtilClass() {
		node = NULL;
		state = 0;
	}
	UtilClass(Node* node, int state) {
		this->state = state;
		this->node = node;
	}

	//state = 0 --> means left me add krna
	//state = 1 --> means right me add krna
	//state = 2 --> means pop krna
};

string serialize(Node* node) {
	if (node == NULL) return "null,";

	string ans = to_string(node->data) + ",";
	ans += serialize(node->left);
	ans += serialize(node->right);

	return ans;
}

Node* deserialize(string data) {
	if (data.size() == 0) return NULL;
	stringstream s(data);
	string str;
	getline(s, str, ',');
	if (str == "null") return NULL;
	Node *root = new Node(stoi(str));
	stack<UtilClass> st;
	st.push(UtilClass(root, 0));
	while (!st.empty()) {
		UtilClass removedObj = st.top();

		if (removedObj.state == 0) {
			getline(s, str, ',');
			if (str != "null") {
				Node* newNode = new Node(stoi(str));
				st.top().node->left = newNode;
				st.top().state++;
				st.push(UtilClass(newNode, 0));
			}
			else {
				st.top().node->left = NULL;
				st.top().state++;
			}
		}

		else if (removedObj.state == 1) { //right me add hoga
			getline(s, str, ',');
			if (str != "null") {
				Node* newNode = new Node(stoi(str));
				st.top().node->right = newNode;
				st.top().state++;
				st.push(UtilClass(newNode, 0));
			}
			else {
				st.top().node->right = NULL;
				st.top().state++;
			}
		}
		else { //state = 2;
			st.pop();
		}
	}
	return root;
}

int main()
{
	vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
	Node* root = construct(arr);
	// display(root);
	string serializeStr = serialize(root);
	cout << "serialize string: " << endl;
	cout << serializeStr << endl;
	root = deserialize(serializeStr);
	cout << "after deserialize" << endl;
	display(root);
}
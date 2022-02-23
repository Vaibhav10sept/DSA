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
void revQueue(queue<Node*> *q) {
	stack<Node*> st;
	// cout << "size " << q->size() << endl;
	while (!q->empty()) {
		st.push(q->front());
		q->pop();
	}
	while (!st.empty())
	{
		q->push(st.top());
		st.pop();
	}
}
//*****************************
//NOTE: THIS IS MY LOGIC
//*****************************


void traversalLevelOrderLineWiseZigzag(Node* root) {
	queue<Node*> mq;
	queue<Node*> cq;
	stack<int> printst;
	queue<int> printq;
	mq.push(root);
	int cnt = 1;
	while (mq.size() > 0 || cq.size() > 0) {
		while (!mq.empty()) {
			Node* mtemp = mq.front();
			mq.pop();
			if (cnt % 2 == 0) {
				printst.push(mtemp->data);

			}
			else {
				printq.push(mtemp->data);

			}
			for (Node* child : mtemp->children) {
				cq.push(child);
			}
		}
		if (cnt % 2 == 0) {
			while (!printst.empty())
			{
				cout << printst.top() << " ";
				printst.pop();
			}
		}
		else {
			while (!printq.empty())
			{
				cout << printq.front() << " ";
				printq.pop();
			}
		}
		cnt++;
		cout << endl;
		while (!cq.empty()) {
			//copying back from mq to cq
			Node* mtemp = cq.front();
			cq.pop();
			mq.push(mtemp);
		}
	}
}

//*****************************
// NOTE: THE ABOVE ONE IS MY LOGIC
// WHICH IS NOT EFFICIENT.
//*****************************


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
	traversalLevelOrderLineWiseZigzag(root);
}
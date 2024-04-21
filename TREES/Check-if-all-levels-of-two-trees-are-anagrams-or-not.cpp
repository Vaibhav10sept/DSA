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

bool areAnagrams(Node *root1, Node *root2)
{
	// NOTE: I Wrote it.
	queue<Node*> q1;
	queue<Node*> q2;

	q1.push(root1);
	q2.push(root2);

	while (!q1.empty() and !q2.empty()) {
		int s1 = q1.size();
		int s2 = q2.size();

		if (s1 != s2 ) return false; //think,cs, logic
		unordered_map<int, int> mp; //int, freq

		for (int i = 0; i < s1; i++) {
			Node* a = q1.front();
			q1.pop();
			Node* b = q2.front();
			q2.pop();

			mp[a->data]++;
			mp[b->data]--;

			//add all neighbours of both a and b
			if (a->left) q1.push(a->left);
			if (b->left) q2.push(b->left);

			if (a->right) q1.push(a->right);
			if (b->right) q2.push(b->right);
		}

		for (auto it : mp) {
			if (it.second != 0) return false;
		}
	}

	return true;
}

int main()
{
	/*
	PREQ: level order traversal of tree using queue
	NOTE: I Wrote it.
	NOTE: I Wrote it.
	LEETCODE: https://practice.geeksforgeeks.org/problems/check-if-all-levels-of-two-trees-are-anagrams-or-not/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	*/

}
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

Node* constructBSTFromSortedArray(vector<int> arr, int low, int high) {
	if (low > high) return NULL;
	int mid = (low + high) / 2;

	Node* leftChild = constructBSTFromSortedArray(arr, low, mid - 1);
	Node* rightChild = constructBSTFromSortedArray(arr, mid + 1, high);

	Node* newNode = new Node(arr[mid], leftChild, rightChild);

	return newNode;

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

bool find(Node* node, int data) {
	if (node == NULL) return false;
	if (find(node->left, data)) return true;
	if (find(node->right, data)) return true;

	if (node->data == data) return true;

	return false;
}

void getSortedArrayFromBST(Node* node, vector<int> &ans) {
	if (node == NULL) {
		return;
	}

	getSortedArrayFromBST(node->left, ans);
	ans.push_back(node->data);
	getSortedArrayFromBST(node->right, ans);

}

void targetSumPairSecondApproach(Node* node, int target) {
	vector<int> SortedArray;
	getSortedArrayFromBST(node, SortedArray);
	//we have sorted array now, so the problem is reduced to target sum
	//pair in sorted array
	//we can solve this using two pointer approach
	int i = 0;
	int j = SortedArray.size() - 1;
	while (i < j) {
		if (SortedArray[i] + SortedArray[j] < target) {
			i++;
		}
		else if (SortedArray[i] + SortedArray[j] > target) {
			j--;
		}
		else {//we found the answer, print it
			cout << SortedArray[i] << " " << SortedArray[j] << endl;
			i++;
			j--;
		}
	}
}

int main()
{
	vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
	Node* root = constructBSTFromSortedArray(arr, 0, arr.size() - 1);
	display(root);
	targetSumPairSecondApproach(root, 75);
}
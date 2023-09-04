#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *right, *down;

};

// Utility function to insert a node at
// beginning of the linked list
Node* push(Node* head_ref, int data)
{

	// Allocate the Node & Put in the data
	Node* new_node = new Node();

	new_node->data = data;
	new_node->right = NULL;

	// Make next of new Node as head
	new_node->down = head_ref;

	// Move the head to point to new Node
	head_ref = new_node;

	return head_ref;
}

void printList(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->down;
	}
	cout << endl;
}

Node* mergeTwoLists(Node* a, Node* b) {

	Node *temp = new Node();
	Node *res = temp;

	while (a != NULL && b != NULL) {
		if (a->data < b->data) {
			temp->down = a;
			temp = temp->down;
			a = a->down;
		}
		else {
			temp->down = b;
			temp = temp->down;
			b = b->down;
		}
	}

	if (a) temp->down = a;
	else temp->down = b;

	return res -> down;

}


Node *flatten(Node *root)
{

	if (root == NULL || root->right == NULL)
		return root;

	// recur for list on right
	root->right = flatten(root->right);

	// now merge
	root = mergeTwoLists(root, root->right);

	// return the root
	// it will be in turn merged with its left
	return root;
}


int main()
{
	/* Let us create the following linked list
	    5 -> 10 -> 19 -> 28
	    |    |     |     |
	    V    V     V     V
	    7    20    22    35
	    |          |     |
	    V          V     V
	    8          50    40
	    |                |
	    V                V
	    30               45
	*/
	Node* head;
	head = push(head, 30);
	head = push(head, 8);
	head = push(head, 7);
	head = push(head, 5);

	head->right = push(head->right, 20);
	head->right = push(head->right, 10);

	head->right->right = push(head->right->right, 50);
	head->right->right = push(head->right->right, 22);
	head->right->right = push(head->right->right, 19);

	head->right->right->right
	    = push(head->right->right->right, 45);
	head->right->right->right
	    = push(head->right->right->right, 40);
	head->right->right->right
	    = push(head->right->right->right, 35);
	head->right->right->right
	    = push(head->right->right->right, 20);

	// Function call
	head = flatten(head);
	printList(head);
}
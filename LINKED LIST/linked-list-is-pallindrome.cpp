#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* next;
	int data;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

void printLinkedList(Node* head) {
	Node* temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* findMidNode(Node* head) {
	Node* slow = head;
	Node* fast = head;

	while (fast->next and fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* reverseLinkedListIterative(Node* head) {
	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;

	while (curr) {
		next  = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

bool isPallindrome(Node* head) {
	// STEPS:
	// 1. find the mid node of linked list
	// 2. reverse the list after the mid node(mid->next)
	// 3. now since the right of half of the LL is reverse you can traverse it in reverse order(think, wv)
	// 4. one pointer at the head and one pointer at the end of LL traverse it and see for the condition of LL.


	//edges case
	if (head == NULL or head->next == NULL) return true; //empty or one size LL is always pallindrome, so return true
	Node* midNode = findMidNode(head);
	cout << "mid " << midNode->data << endl;
	Node* last = reverseLinkedListIterative(midNode->next);

	Node* first = head;
	while (last) {
		if (last->data != first->data) return false;
		last = last->next;
		first = first->next;
	}

	return true;
}


int main()
{
	/*
	VIDEO: https://www.youtube.com/watch?v=ee-DuKtRNGw
	LEETCODE: https://leetcode.com/problems/palindrome-linked-list/description/
	// STEPS:
	// 1. find the mid node of linked list
	// 2. reverse the list after the mid node(mid->next)
	// 3. now since the right of half of the LL is reverse you can traverse it in reverse order(think, wv)
	// 4. one pointer at the head and one pointer at the end of LL traverse it and see for the condition of LL.
	*/
	Node* head = new Node(0);
	Node* newNode;

	newNode = new Node(1);
	head->next = newNode;

	newNode = new Node(2);
	head->next->next = newNode;

	newNode = new Node(2);
	head->next->next->next = newNode;

	newNode = new Node(1);
	head->next->next->next->next = newNode;

	newNode = new Node(0);
	head->next->next->next->next->next = newNode;

	// printLinkedList(head);
	if (isPallindrome(head)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}
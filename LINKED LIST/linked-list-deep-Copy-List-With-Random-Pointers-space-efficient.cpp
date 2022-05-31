#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* next;
	int data;
};

class LinkedList
{
	/*********************************************
	 * LINKED LIST BOILER PLATE CODE STARTS
	 * *******************************************/
public:
	Node* head;
	Node* tail;
	int size;

	LinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	int getSize() {
		Node* temp = head;
		int res = 0;
		while (temp) {
			temp = temp->next;
			res++;
		}
		return res;
	}

	void removeFirst() {
		if (size == 0) {
			cout << "list is empty" << endl;
			return;
		}
		else if (size == 1) {
			free(head);
			head = tail = NULL;
		}
		else {
			Node* temp = head;
			head = head->next;
			free(temp);
		}
		size--;
	}

	int getFirst() {
		if (size == 0 || head == NULL) {
			cout << "list is empty" << endl;
			return -1;
		}
		else {
			return head->data;
		}
	}

	int getLast() {
		if (size == 0 || head == NULL) {
			cout << "list is empty" << endl;
			return -1;
		}
		else {
			return tail->data;
		}
	}

	int getAtIdx(int idx) {
		if (idx < 0 || idx >= size) {
			cout << "not a valid index" << endl;
			return -1;
		}
		else if (size == 0 || head == NULL) {
			cout << "list is empty" << endl;
		}
		else if ( idx == 0 ) {
			return getFirst();
		}
		else {
			Node* temp = head;
			for (int i = 0; i < idx; i++) {
				temp = temp->next;
			}
			return temp->data;
		}

	}

	void addLastModified(Node* node, map<Node*, Node*> &mp) {
		Node* newNode = new Node();
		newNode->data = node->data;
		newNode->next = NULL;

		if (size == 0) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		size++;
		mp[node] = newNode;
	}

	void addFirst(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = NULL;

		if (size == 0) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		size++;
	}

	void addAtIdx(int data, int idx) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = NULL;
		if (idx < 0 || idx >= size) {
			cout << "not a valid index" << endl;
			return;
		}
		else if (idx == 0) {
			addFirst(data);
		}
		else {
			Node* temp = head;
			for (int i = 0; i < idx - 1; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		size++;
	}

	void removeLast() {
		if (size == 0) {
			cout << "nothing to be removed" << endl;
			return;
		}
		else if (size == 1) {
			head = tail = NULL;
		}
		else {
			Node* temp = head;
			for (int i = 0; i < size - 2; i++) {
				temp = temp->next;
			}
			free(tail);
			temp->next = NULL;
			tail = temp;
		}

		size--;

	}

	void removeAtIdx(int idx) {
		if (idx < 0 || idx >= size) {
			cout << "not a valid index" << endl;
			return;
		}
		else if (size == 0) {
			cout << "nothing to be removed" << endl;
			return;
		}
		else if (size == 1) {
			head = tail = NULL;
		}
		else if (idx == 0) {
			head = head->next;
		}
		else {
			Node* temp = head;
			for (int i = 0; i < idx - 1; i++) {
				temp = temp->next;
			}
			Node* tobefreed = temp->next;
			temp->next = temp->next ? temp->next->next : NULL;
			free(tobefreed);
		}
		size--;
	}

	void printLinkedList() {
		Node* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	/*********************************************
	 * LINKED LIST BOILER PLATE CODE ENDS
	 * *******************************************/
};

class ListNode {
public:
	ListNode* next;
	ListNode* random;
	int val;

	ListNode(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
ListNode* CopyListWithRandomPointers(ListNode* head) {
	/*
	watch video recommended
	good question
	rem the approach used
	*/
	ListNode* curr = head;
	while (curr) {
		ListNode* next = curr->next;

		ListNode* newNode = new ListNode(curr->val);
		curr->next = newNode;
		newNode->next = next;

		curr = next;
	}

	//copy random pointers
	curr = head;
	while (curr) {
		//think,logic, watch video (crucial point of algorithm)
		curr->next->random = curr->random != NULL ? curr->random->next : NULL;

		//move curr
		curr = curr->next->next;
	}

	//extract copied list and restore the original list.
	ListNode dummy = new ListNode(-1);
	ListNode prev = dummy;
	curr = head;

	while (curr) {
		prev->next = curr->next;
		curr->next = curr->next->next;

		//move
		prev = prev->next;
		curr = curr->next;
	}

	return dummy->next; //head of copied list.
}

int main()
{
	/*
	NOTE: THIS QUESTION CANNOT BE EXECUTED.
	NOTE: this is space efficient solution
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=IGWJg9wDaF0&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=15
	LEETCODE LINK: https://leetcode.com/problems/copy-list-with-random-pointer/
	*/
	cout << "this question cannot be executed, as the test case is not there" << endl;

}
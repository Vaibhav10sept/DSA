#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* next;
	int data;
	Node(int val) {
		data = val;
		next = NULL;
	}
	Node() {
		next = NULL;
	}
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

	void addLast(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = NULL;

		if (size == 0) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		size++;
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
		cout << "idx" << idx << endl;
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
	void print(Node* head) {
		Node* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void segregate01LinkedList() {
		Node* curr = head;
		Node* prevZero = NULL;
		Node* prevOne = NULL;
		Node* prevZeroHead = NULL;
		Node* prevOneHead = NULL;

		while (curr) {
			if (curr->data == 0) {
				if (prevZero == NULL) {
					prevZero = curr;
					prevZeroHead = curr;
				}
				else {
					prevZero->next = curr;
					prevZero = prevZero->next;
				}
			}
			else { //curr->data == 1
				if (prevOne == NULL) {
					prevOne = curr;
					prevOneHead = curr;
				}
				else {
					prevOne->next = curr;
					prevOne = prevOne->next;
				}
			}
			curr = curr->next;
		}
		prevZero != NULL ? prevZero->next = NULL : NULL;
		prevOne != NULL ? prevOne->next = NULL : NULL;

		//edge cases/ linking prevzerohead and prevonehead.
		if (prevZero != NULL) {
			prevZero->next = prevOneHead;
		}
		if (prevZeroHead != NULL) {
			head = prevZeroHead;
		}
		else {
			head = prevOneHead;
		}
	}
};


int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=j_w83pJ6Px0&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=28
	PREREQUISITE: segregate 0 and 1 linked list
	*/
	LinkedList ll;
	ll.addFirst(1);
	ll.addFirst(0);
	ll.addFirst(1);
	ll.addFirst(0);
	ll.addFirst(0);
	ll.addFirst(1);
	ll.addFirst(1);
	ll.addFirst(1);
	ll.addFirst(0);
	ll.addFirst(0);
	ll.addFirst(0);
	ll.addFirst(1);
	ll.addFirst(1);
	ll.printLinkedList();
	cout << "after segregating 0 and 1: " << endl;
	ll.segregate01LinkedList();
	ll.printLinkedList();

}
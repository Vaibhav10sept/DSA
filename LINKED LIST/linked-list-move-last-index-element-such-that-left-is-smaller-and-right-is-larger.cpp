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
	Node(int val, Node* next) {
		data = val;
		this->next = next;
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
		if (head == NULL or head->next == NULL) return; //edge case--> empty list or 1 size list
		int pivot = this->getLast(); //coz, last index vali value ko hi pivot bna rhe

		Node* curr = head;
		Node* smaller = NULL;
		Node* larger = NULL;
		Node* smallerHead = NULL;
		Node* largerHead = NULL;

		while (curr) {
			if (curr->data <= pivot) {
				if (smaller == NULL) {
					smaller = curr;
					smallerHead = curr;
				}
				else {
					smaller->next = curr;
					smaller = smaller->next;
				}
			}
			else { //curr->data > pivot
				if (larger == NULL) {
					larger = curr;
					largerHead = curr;
				}
				else {
					larger->next = curr;
					larger = larger->next;
				}
			}
			curr = curr->next;
		}

		smaller != NULL ? smaller->next = largerHead : NULL;
		larger != NULL ? larger->next = NULL : NULL;
		// cout << "print " << endl;
		// print(smallerHead);
		// print(largerHead);
		//edge cases/ linking prevzerohead and prevonehead.

		if (smallerHead != NULL) {
			head = smallerHead;
		}
		else {
			head = largerHead;
		}
	}
};


int main()
{
	/*
	NOTE: this is partition in quick sort isme ham last index vali value ko uski correct position in sorted list me laege.
	VIDEO LINK: https://www.youtube.com/watch?v=R9ak6JgWMAw&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=30
	PREREQUISITE: "segregate 0 and 1 linked list"
	*/
	LinkedList ll;
	ll.addLast(1);
	ll.addLast(5);
	ll.addLast(2);
	ll.addLast(9);
	ll.addLast(5);
	ll.addLast(14);
	ll.addLast(11);
	ll.addLast(1);
	ll.addLast(10);
	ll.addLast(10);
	ll.addLast(1);
	ll.addLast(3);
	ll.printLinkedList();
	cout << "after partition as per quick sort: " << endl;
	ll.segregate01LinkedList();
	ll.printLinkedList();
}
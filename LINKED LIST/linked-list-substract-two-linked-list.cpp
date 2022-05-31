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

int substract(Node* l1, Node* l2, int f1, int f2, LinkedList *res) {
	// f1 -> one ki face value
	// f2 -> two ki face value
	if (f1 == 0 && f2 == 0) return 0; // we are returning carry here.
	if (f1 > f2) {
		int borrow = substract(l1->next, l2, f1 - 1, f2, res);
		int diff = l1->data + borrow;
		if (diff != 0) res->addFirst(diff);

		return 0; // this is the borrow
	}
	//NOTE: f2 > f1, is not going to happen as it is given that number1 is always greater than number 2(in question)
	else {
		// f1 == f2
		int borrow = substract(l1->next, l2->next, f1 - 1, f2 - 1, res);
		l1->data = l1->data + borrow;
		borrow = 0;
		int diff = l1->data - l2->data;
		if (diff < 0) { //we need to take borrow
			borrow = -1;
			l1->data += 10;
		}
		diff = l1->data - l2->data;
		if (diff != 0) res->addFirst(diff);

		return borrow;
	}

}




int main()
{
	/*
	PREREQUISITE: addition of two linked list
	NOTE: here number 1 is always greater than number 2(given in question)
	VIDEO LINK: https://www.youtube.com/watch?v=U5Ix-rscbl4&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=23

	*/
	LinkedList ll;
	ll.addLast(1);
	ll.addLast(0);
	ll.addLast(0);

	cout << "number 1" << endl;

	ll.printLinkedList();
	LinkedList l2;
	l2.addLast(1);
	l2.addLast(2);

	cout << "number 2" << endl;
	l2.printLinkedList();

	LinkedList res;
	int extraCarry = substract(ll.head, l2.head, ll.size, l2.size, &res);
	if (extraCarry != 0) {
		res.addFirst(extraCarry);
	}
	cout << "after n1 - n2:" << endl;
	res.printLinkedList();
}
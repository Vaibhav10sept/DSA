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

int add(Node* l1, Node* l2, int f1, int f2, LinkedList *res) {
	// f1 -> one ki face value
	// f2 -> two ki face value
	if (f1 == 0 && f2 == 0) return 0; // we are returning carry here.
	if (f1 > f2) {
		int carry = add(l1->next, l2, f1 - 1, f2, res);
		int sum = l1->data + carry;
		int rem = sum % 10;
		sum /= 10;
		res->addFirst(rem);
		return sum; // this is the carry
	}
	else if (f2 > f1) {
		int carry = add(l1, l2->next, f1, f2 - 1, res);
		int sum = l2->data + carry;
		int rem = sum % 10;
		sum /= 10;
		res->addFirst(rem);
		return sum;
	}
	else {
		// f1 == f2
		int carry = add(l1->next, l2->next, f1 - 1, f2 - 1, res);
		int sum = l1->data + l2->data + carry;
		int rem = sum % 10;
		sum /= 10;
		res->addFirst(rem);
		return sum;
	}
}




int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=tK4eez3syAQ&t=264s
	*/
	LinkedList ll;
	ll.addLast(9);
	ll.addLast(7);
	// ll.addLast(8);
	// ll.addLast(5);
	cout << "number 2" << endl;

	ll.printLinkedList();
	LinkedList l2;
	l2.addLast(4);
	l2.addLast(6);
	l2.addLast(4);
	l2.addLast(6);
	cout << "number 1" << endl;
	l2.printLinkedList();

	LinkedList res;
	int extraCarry = add(ll.head, l2.head, ll.size, l2.size, &res);
	if (extraCarry != 0) {
		res.addFirst(extraCarry);
	}
	cout << "result" << endl;
	res.printLinkedList();
}
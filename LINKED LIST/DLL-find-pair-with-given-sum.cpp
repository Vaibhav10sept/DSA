#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* next;
	Node* prev;
	int data;

	Node(int data) {
		this->data = data;
		next = NULL;
		prev = NULL;
	}
	Node() {
		next = NULL;
		prev = NULL;
	}
};

class DoublyLinkedList
{
	/*********************************************
	 * DOUBLY LINKED LIST BOILER PLATE CODE STARTS
	 * *******************************************/
public:
	Node* head;
	Node* tail;
	int size;

	DoublyLinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	int getFirst() {
		if (size == 0) {
			cout << "list is empty" << endl;
			return -1;
		}
		else return head->data;
	}

	int getLast() {
		if (size == 0) {
			cout << "list is empty" << endl;
			return -1;
		}
		else return tail->data;
	}

	int getAtIdx(int idx) {
		if (idx < 0 || idx >= size) {
			cout << "not a valid index" << endl;
			return -1;
		}
		else if (size == 0 || head == NULL) {
			cout << "list is empty" << endl;
		}
		else {
			Node* temp = head;
			for (int i = 0; i < idx; i++) {
				temp = temp->next;
			}
			return temp->data;
		}
	}

	void addAtIdx(int data, int idx) {
		Node* newNode = new Node(data);

		if (idx < 0 || idx > size) {
			cout << "not a valid index" << endl;
			return;
		}
		else if (idx == 0) {
			addFirst(data);
		}
		else if (idx == size) {
			addLast(data);
		}
		else {
			Node* temp = head;
			for (int i = 0; i < idx - 1; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next->prev = newNode;

			temp->next = newNode;
			newNode->prev = temp;
		}
		size++;
	}

	void removeAtIdx(int idx) {
		if (size == 0) {
			cout << "nothing to be removed" << endl; \
			return;
		}
		if (idx < 0 || idx >= size) {
			cout << "not a valid index" << endl;
			return;
		}
		else if (idx == 0) {
			removeFirst();
		}
		else if (idx == size - 1) {
			removeLast();
		}
		else {
			Node* temp = head;
			for (int i = 0; i < idx - 1; i++) {
				temp = temp->next;
			}
			temp->next = temp->next->next;
			temp->next->prev = temp;
		}
		size--;
	}

	void addFirst(int val) {
		if (size == 0) { //list is empty
			Node* newNode = new Node(val);
			tail = head = newNode;
		}
		else { //list has more than 1 nodes
			Node* newNode = new Node(val);
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		size++;
	}

	void addLast(int val) {
		if (size == 0) { //list is empty
			Node* newNode = new Node(val);
			tail = head = newNode;
		}
		else { //list has more than 1 nodes
			Node* newNode = new Node(val);
			tail->next = newNode;
			newNode->prev = tail;
		}
		size++;
	}

	void removeFirst() {
		if (size == 0) {
			cout << "nothing to be removed" << endl;
			return;
		}
		else if (size == 1) {
			head = tail = NULL;
		}
		else {
			Node* temp = head;
			head = head->next;
			head->prev = NULL;
			free(temp);
		}
		size--;
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
			Node* temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			free(temp);
		}
		size--;
	}

	printDoublyLinkedList() {
		Node* temp = head;
		while (temp) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}

	printReverseDoublyLinkedList() {
		Node* temp = tail;
		while (temp) {
			cout << temp->data << endl;
			temp = temp->prev;
		}
	}


	/*********************************************
	 * DOUBLY LINKED LIST BOILER PLATE CODE ENDS
	 * *******************************************/
};

void findPairWithGivenSum(DoublyLinkedList ll, int x)
{
	// Set two pointers, first to the beginning of DLL
	// and second to the end of DLL.
	Node* head = ll.head;
	Node *first = head;
	Node *second = head;
	while (second->next != NULL)
		second = second->next;

	// The loop terminates when two pointers
	// cross each other (second->next
	// == first), or they become same (first == second)
	while (first != second && second->next != first)
	{
		// pair found
		if ((first->data + second->data) == x)
		{
			cout << "(" << first->data << ", "
			     << second->data << ")" << endl;

			// move first in forward direction
			first = first->next;

			// move second in backward direction
			second = second->prev;
		}
		else
		{
			if ((first->data + second->data) < x)
				first = first->next;
			else
				second = second->prev;
		}
	}
}


int main()
{
	DoublyLinkedList ll;
	ll.addFirst(3);
	ll.addFirst(2);
	ll.addFirst(1);
	ll.printDoublyLinkedList();
	cout << "res" << endl;
	findPairWithGivenSum(ll, 5);
}
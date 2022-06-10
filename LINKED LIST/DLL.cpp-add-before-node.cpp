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

	Node* getNodeAtIdx(int idx) {
		if (idx < 0 || idx >= size) {
			cout << "not a valid index" << endl;
			return NULL;
		}
		else if (size == 0 || head == NULL) {
			cout << "list is empty" << endl;
			return NULL;
		}
		else if ( idx == 0 ) {
			return head;
		}
		else {
			Node* temp = head;
			for (int i = 0; i < idx; i++) {
				temp = temp->next;
			}
			return temp;
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
		size++;
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

	void addBeforeNode(Node* node, int val) {
		Node* temp  = head;
		while (temp) {
			if (temp == node) { //node found
				if (temp->prev == NULL) {
					//temp is the head node, vo insertion me head ko change krna hoga
					Node* newNode = new Node(val);
					newNode->next = head;
					head->prev = newNode;
					head = newNode;
				}
				else {
					//head ke alava in between node insert krna hai
					Node* newNode = new Node(val);
					Node* prev = temp->prev;
					//inserting newnode in between temp and prev
					prev->next = newNode;
					newNode->prev = prev;
					temp->prev = newNode;
					newNode->next = temp;
				}
			}
			temp = temp->next;
		}
	}

};


int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=SZ-dVOrG-M8&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=41
	*/
	DoublyLinkedList ll;
	ll.addFirst(6);
	ll.addFirst(5);
	ll.addFirst(4);
	ll.addFirst(3);
	ll.addFirst(2);
	ll.addFirst(1);
	ll.printDoublyLinkedList();
	Node* node = ll.getNodeAtIdx(2); //data -> 3
	ll.addBeforeNode(node, 10);
	cout << "after" << endl;
	ll.printDoublyLinkedList();
	cout << "reverse" << endl;
	ll.printReverseDoublyLinkedList();
}
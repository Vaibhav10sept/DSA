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
		while (temp != NULL) {
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

	void printCircularLinkedList() {
		Node* temp = head;
		while (temp->next != head) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data;
		cout << endl;
	}
	/*********************************************
	 * LINKED LIST BOILER PLATE CODE ENDS
	 * *******************************************/
};

void deleteFromCircularLinkedList(LinkedList &ll, int key) {
	Node* head = ll.head;

	if (head == NULL) return;

	//if one size circular li
	if (head->data == key and head->next == head) {
		free(head);
		ll.removeFirst();
		return;
	}

	//if head is the node to be deleted
	if (head->data == key) {
		ll.removeFirst();
		//make it circular
		ll.tail->next = ll.head;
		return;
	}

	Node* temp = head;
	while (temp->next != head and temp->next->data != key) {
		temp = temp->next;
	}

	if (temp->next->data == key) { //means temp->next ko delete krna h
		//think: if the node to be deleted is the last node, then also it will work, dry run and think
		Node* tobefreed = temp->next;
		temp->next = tobefreed->next; //think: if key is the last node, then tobefreed->next is the head, so by doing temp->next = tobefreed->next we are making the li as circular as well, think, cs
		free(tobefreed);
		return;

	}
	else {
		cout << "the data is not found" << endl;
		return;
	}

	return;
}


int main()
{
	LinkedList ll;
	ll.addFirst(3);
	ll.addFirst(2);
	ll.addFirst(1);

	//make it a circular ll
	ll.tail->next = ll.head;

	ll.printCircularLinkedList();
	deleteFromCircularLinkedList(ll, 3);
	cout << "after deletion" << endl;
	ll.printCircularLinkedList();
}
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

	Node* reverseLinkedListIterative(Node* head) {
		//edge case --> empty or one size ki linked list
		if (head == NULL or head->next == NULL) return head;

		Node* prev = NULL;
		Node* next = NULL;
		Node* curr = head;

		while (curr) {
			//backup
			next = curr->next;
			//links
			curr->next = prev;
			//move
			prev = curr;
			curr = next;
		}

		return prev;
	}
	void unFold() {
		//watch video recommended
		//edge case --> empty or one size ki linked list
		if (head == NULL or head->next == NULL) return;

		Node* firstHead = head;
		Node* firstPrevious = head;

		Node* secondHead = head->next;
		Node* secondPrevious = head->next;

		while (secondPrevious != NULL and secondPrevious->next != NULL) { //while ki 1st condition even lenght ko handle krega or while ki 2nd condition odd lenght ke lie hai(dry run, think, watch video)
			Node* forward = secondPrevious->next;

			//links
			firstPrevious->next = forward;
			secondPrevious->next = forward->next;

			//move
			firstPrevious = firstPrevious->next;
			secondPrevious = secondPrevious->next;
		}
		firstPrevious->next = NULL;

		secondHead = reverseLinkedListIterative(secondHead);
		firstPrevious->next = secondHead;
	}
};


int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=GjhGhEoZ1Vk&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=5
	GFG LINK: https://www.geeksforgeeks.org/program-to-unfold-a-folded-linked-list/
	PREREQUISITE: fold a linked list
	*/
	LinkedList ll;
	// ll.addFirst(4);
	ll.addFirst(3);
	ll.addFirst(4);
	ll.addFirst(2);
	ll.addFirst(5);
	ll.addFirst(1);
	ll.printLinkedList();
	ll.unFold();
	cout << "after unfolding" << endl;
	ll.printLinkedList();
}
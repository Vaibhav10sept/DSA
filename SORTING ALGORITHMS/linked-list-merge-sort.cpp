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
Node* midNode(Node* head, Node* tail) {
	// cout << "MID" << endl;
	Node* s = head;
	Node* f = head;
	int res = 0;
	while (f != tail && f->next != tail) {
		f = f->next->next;
		s = s->next;
		res++;
	}
	return s;
}

LinkedList merge(LinkedList left, LinkedList right) {
	LinkedList res;
	Node* l = left.head;
	Node* r = right.head;

	while (l != NULL && r != NULL) {
		if (l->data < r->data) {
			res.addLast(l->data);
			l = l->next;
		}
		else {
			res.addLast(r->data);
			r = r->next;
		}
	}
	while (l) {
		res.addLast(l->data);
		l = l->next;
	}
	while (r) {
		res.addLast(r->data);
		r = r->next;
	}
	return res;
}


LinkedList mergeSort(Node * head, Node * tail) {
	if (head == tail ) {
		LinkedList newll;
		newll.addLast(head->data);
		return newll;
	}

	Node* mid = midNode(head, tail);

	LinkedList left = mergeSort(head, mid);
	LinkedList right = mergeSort(mid->next, tail);
	LinkedList merged = merge(left, right);

	return merged;
}

int main()
{
	/*
	NOTE: search again more optimized solution is there.
	SPACE: O(logn)
	TIME: O(nlogn)
	*/
	LinkedList ll1;
	ll1.addFirst(0);
	ll1.addFirst(9);
	ll1.addFirst(5);
	ll1.addFirst(7);
	ll1.addFirst(4);
	ll1.addFirst(10);
	ll1.printLinkedList();
	LinkedList mergedList = mergeSort(ll1.head, ll1.tail);
	cout << "after merge sort" << endl;
	mergedList.printLinkedList();

}
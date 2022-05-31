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

LinkedList MergeTwoSortedLinkedList(LinkedList left, LinkedList right) {
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

LinkedList MergeKSortedLinkedListHelper(vector<LinkedList> lists, int startIdx, int endIdx) {
	//BASE COND
	// if (startIdx > endIdx) {
	// 	LinkedList empty;
	// 	return empty;
	// }
	if (startIdx == endIdx) return lists[startIdx];

	int mid = (startIdx + endIdx) / 2;

	LinkedList l1 = MergeKSortedLinkedListHelper(lists, startIdx, mid);
	LinkedList l2 = MergeKSortedLinkedListHelper(lists, mid + 1, endIdx);

	return MergeTwoSortedLinkedList(l1, l2);
}

LinkedList MergeKSortedLinkedList(vector<LinkedList> lists) {
	//the code pattern is very much similar to mergesort linked list
	return MergeKSortedLinkedListHelper(lists, 0, lists.size() - 1);
}

int main()
{
	/*
	NOTE: the steps are similar to merge sort in linked list
	PREREQUISITE: merge sort in linked list
	VIDEO LINK: https://www.youtube.com/watch?v=wugaUVZ8PVw&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=7
	*/
	LinkedList ll1;
	ll1.addFirst(6);
	ll1.addFirst(5);
	ll1.addFirst(4);
	ll1.addFirst(3);
	ll1.addFirst(2);
	ll1.addFirst(1);

	LinkedList ll2;
	ll2.addFirst(12);
	ll2.addFirst(11);
	ll2.addFirst(10);
	ll2.addFirst(9);
	ll2.addFirst(8);
	ll2.addFirst(7);

	vector<LinkedList> lists;
	lists.push_back(ll1);
	lists.push_back(ll2);
	LinkedList res = MergeKSortedLinkedList(lists);
	cout << "after merging" << endl;
	res.printLinkedList();
}
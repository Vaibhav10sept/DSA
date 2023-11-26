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

Node* MergeTwoSortedLinkedList(Node* left, Node* right) {
	//NOTE: this merge function will take constant space, use this instead of any other merge approach
	// in LL this take constant space, but in array this function takes n space
	//that is why space of merge sort in array is n and in LL is logn(this logn is due to the stack/auxilliary space of recursion)
	Node* temp = new Node();
	temp->data = -1;
	temp->next = NULL;
	Node* head = temp;
	Node* l = left;
	Node* r = right;

	while (l != NULL && r != NULL) {
		if (l->data < r->data) {
			temp->next = l;
			l = l->next;
			temp = temp->next;
		}
		else {
			temp->next = r;
			r = r->next;
			temp = temp->next;
		}
	}

	while (l) {
		temp->next = l;
		l = l->next;
		temp = temp->next;
	}
	while (r) {
		temp->next = r;
		r = r->next;
		temp = temp->next;
	}
	return head->next;
}

Node* MergeKSortedLinkedListHelper(vector<Node*> lists, int startIdx, int endIdx) {
	//BASE COND
	if (startIdx == endIdx) return lists[startIdx];

	int mid = (startIdx + endIdx) / 2;

	Node* l1 = MergeKSortedLinkedListHelper(lists, startIdx, mid);
	Node* l2 = MergeKSortedLinkedListHelper(lists, mid + 1, endIdx);

	return MergeTwoSortedLinkedList(l1, l2);
}

Node* MergeKSortedLinkedList(vector<Node*> lists) {
	//the code pattern is very much similar to mergesort linked list
	return MergeKSortedLinkedListHelper(lists, 0, lists.size() - 1);
}

int main()
{
	/*
	NOTE: the steps are similar to merge sort in linked list
	PREREQUISITE: merge sort in linked list
	QUESTION: https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
	VIDOE LINK: https://www.youtube.com/watch?v=Q64u-W3l3mA
	VIDEO LINK: https://www.youtube.com/watch?v=wugaUVZ8PVw&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=7
	*/
	Node* ll1 = new Node(1);
	ll1->next = new Node(3);
	ll1->next->next = new Node(5);


	Node* ll2 = new Node(2);
	ll2->next = new Node(4);


	// LinkedList ll1;
	// ll1.addFirst(6);
	// ll1.addFirst(5);
	// ll1.addFirst(4);
	// ll1.addFirst(3);
	// ll1.addFirst(2);
	// ll1.addFirst(1);

	// LinkedList ll2;
	// ll2.addFirst(12);
	// ll2.addFirst(11);
	// ll2.addFirst(10);
	// ll2.addFirst(9);
	// ll2.addFirst(8);
	// ll2.addFirst(7);

	vector<Node*> lists;
	lists.push_back(ll1);
	lists.push_back(ll2);
	Node* res = MergeKSortedLinkedList(lists);
	cout << "after merging" << endl;
	while (res != NULL) {
		cout << res->data << " ";
		res = res->next;
	}
}
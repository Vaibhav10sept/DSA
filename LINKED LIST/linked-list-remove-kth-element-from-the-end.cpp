#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* next;
	int data;

	Node(int ele) {
		data = ele;
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
	void kthElementFromEnd(int k) {
		//using slow, fast pointer approach
		//SLOW IS A DOUBLE POINTER, THINK, SEE LINK.
		//LOGIC: slow(double pointer) point krega uss node ko jise remove krna hai, uske peeche vali node ko point nhi krega, rem, thats why double pointer use kr rhe hai
		Node** slow = &head;
		Node* fast = head;

		//dry run krne for ki values nikallo jaese pehle krte the, no need to memorize anything
		for (int i = 1; i < k; i++) fast = fast->next;

		while (fast->next != NULL) {
			fast = fast->next;
			slow = &((*slow)->next);
		}
		//slow(double pointer) ko uss node pe lao jise remove krna hai,
		*slow = (*slow)->next;
	}

	Node* kthElementFromEnd2(int k) {
		//this code is from the video(link below)
		Node* start = new Node(-1);
		start->next = head;
		Node* slow = start;
		Node* fast = start;

		for (int i = 1; i <= k; i++) fast = fast->next;

		while (fast->next != NULL) {
			fast = fast->next;
			slow = slow->next;
		}

		slow->next = slow->next->next;

		return start->next;
	}
};


int main()
{
	/*
	NOTE: two functions are written as the solutions for this question
	VIDEO LINK: https://www.youtube.com/watch?v=Lhu3MsXZy-Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=31
	LEETCODE SOLUTION LINK: https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/8812/My-short-C%2B%2B-solution
	*/
	LinkedList ll;
	// ll.addFirst(5);
	// ll.addFirst(4);
	// ll.addFirst(3);
	ll.addFirst(2);
	ll.addFirst(1);
	// ll.addFirst(0);
	ll.printLinkedList();
	cout << "result" << endl;
	// ll.kthElementFromEnd(1);
	ll.head = ll.kthElementFromEnd2(1);
	ll.printLinkedList();
}
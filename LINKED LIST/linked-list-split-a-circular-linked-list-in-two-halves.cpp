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
		cout << "idx" << idx << endl;
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
	void printCircularLinkedList() {
		Node* temp = head;
		while (temp->next != head) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data;
		cout << endl;
	}

	Node* middle() {
		Node* slow = head;
		Node* fast = head;

		while (fast->next != head && fast->next->next != head) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};

void printCircularLinkedList(Node* head) {
	Node* temp = head;
	while (temp->next != head) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data;
	cout << endl;
}

void splitCircularLinkedListInTwoHalves(LinkedList ll, Node** head1_ref, Node** head2_ref) {
	Node* head = ll.head;

	Node* midNode = ll.middle();

	*head1_ref = head;
	*head2_ref = midNode->next;
	// make first li circular
	midNode->next = *head1_ref;

	//make second li circular
	Node* temp = *head2_ref;
	while (temp->next != head) {
		temp = temp->next;
	}
	//now, temp is the last node of the given li
	//create second li circular
	temp->next = *head2_ref;
}

void splitCircularLinkedListInTwoHalvestest(LinkedList ll, Node** head1_ref, Node** head2_ref) {
	Node* head = ll.head;
	Node* slow = head;
	Node* fast = head;

	while (fast->next != head and fast->next->next != head) {
		slow = slow->next;
		fast = fast->next->next;
	}

	*head2_ref = slow->next;
	*head1_ref = head;

	//move fast to the end of ll
	while (fast->next != head) {
		fast = fast->next;
	}

	fast->next = *head2_ref;
	slow->next = *head1_ref;
}


int main()
{
	/*
	VIDOE LINK: https://www.youtube.com/watch?v=NM1pYrOC5vU
	QUESTION LINK: https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/
	*/
	LinkedList ll;
	ll.addFirst(3);
	ll.addFirst(2);
	ll.addFirst(1);

	//make it a circular ll
	ll.tail->next = ll.head;

	ll.printCircularLinkedList();
	Node* first;
	Node* second;
	splitCircularLinkedListInTwoHalvestest(ll, &first, &second);
	cout << "after split" << endl;
	printCircularLinkedList(first);
	printCircularLinkedList(second);
}
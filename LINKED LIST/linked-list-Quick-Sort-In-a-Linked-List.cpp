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
	Node(int val, Node* next) {
		data = val;
		this->next = next;
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

	Node* getNodeAtIdx(int idx) {
		if (idx < 0 || idx >= size) {
			cout << "not a valid index" << endl;
			return NULL;
		}
		else if (size == 0 || head == NULL) {
			cout << "list is empty" << endl;
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
};

void print(Node* head) {
	Node* temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

class utilContainerQuickSort {
public:
	Node* head;
	Node* tail;

	utilContainerQuickSort(Node* head, Node* tail) {
		this->head = head;
		this->tail = tail;
	}
};


class utilContainerPartition {
public:
	Node* smallerHead;
	Node* largerHead;
	Node* pivotNode;

	utilContainerPartition(Node* smallerHead, Node* pivotNode, Node* largerHead) {
		this->smallerHead = smallerHead;
		this->largerHead = largerHead;
		this->pivotNode = pivotNode;
	}
};

int getLength(Node* head) {
	if (head == NULL) return 0;

	int len = 0;
	Node* temp = head;
	while (temp) {
		len++;
		temp = temp->next;
	}
	return len;
}

Node* getNodeAtIdx(Node* head, int idx) {
	if (idx < 0) {
		cout << "not a valid index" << endl;
		return NULL;
	}
	else if (head == NULL) {
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

utilContainerQuickSort mergeSortedLists(utilContainerQuickSort leftSortedData, Node* pivotNode, utilContainerQuickSort rigthSortedData) {
	Node* head = NULL;
	Node* tail = NULL;

	//there can be 4 cases
	//1. left != null and right != null
	//2. left != null and right == null
	//3. left == null and right != null
	//4. left == null and right == null

	if (leftSortedData.head != NULL and rigthSortedData.head != NULL) {
		leftSortedData.tail->next = pivotNode;
		pivotNode->next = rigthSortedData.head;
		head = leftSortedData.head;
		tail = rigthSortedData.tail;
	}
	else if (leftSortedData.head != NULL) {
		leftSortedData.tail->next = pivotNode;
		head = leftSortedData.head;
		tail = pivotNode;
	}
	else if (rigthSortedData.head != NULL) {
		pivotNode->next = rigthSortedData.head;
		head = pivotNode;
		tail = rigthSortedData.tail;
	}
	else { //case->4: both left and right are null
		head = tail = pivotNode;
	}

	return utilContainerQuickSort(head, tail);
}

utilContainerPartition partition(Node* head, int pivotIdx) {
	//this is almost same code as in "linked-list-move-last-index-element-such-that-left-is-smaller-and-right-is-larger"
	Node* pivotNode = getNodeAtIdx(head, pivotIdx);
	int pivot = pivotNode->data;

	Node* curr = head;
	Node* smaller = NULL;
	Node* larger = NULL;
	Node* smallerHead = NULL;
	Node* largerHead = NULL;

	while (curr) {
		if (curr == pivotNode) {
			curr = curr->next;
			continue; //pivot node ko ham baad me link krege
		}
		if (curr->data <= pivot) {
			if (smaller == NULL) {
				smaller = curr;
				smallerHead = curr;
			}
			else {
				smaller->next = curr;
				smaller = smaller->next;
			}
		}
		else { //curr->data > pivot
			if (larger == NULL) {
				larger = curr;
				largerHead = curr;
			}
			else {
				larger->next = curr;
				larger = larger->next;
			}
		}
		curr = curr->next;
	}

	smaller != NULL ? smaller->next = NULL : NULL;
	pivotNode->next = NULL;
	larger != NULL ? larger->next = NULL : NULL;

	return utilContainerPartition(smallerHead, pivotNode, largerHead);
}

utilContainerQuickSort quickSortHelper(Node* head) {
	//base case --> list is empty or having one size.
	if (head == NULL or head->next == NULL) {
		return utilContainerQuickSort(head, head);
	}

	int len = getLength(head);
	int pivotIdx = len / 2;

	utilContainerPartition partitionedData = partition(head, pivotIdx);

	//left call of quick sort, to get the left sorted list.
	utilContainerQuickSort leftSortedData = quickSortHelper(partitionedData.smallerHead);
	//right call of quick sort, to get the right sorted list.
	utilContainerQuickSort rigthSortedData = quickSortHelper(partitionedData.largerHead);

	return mergeSortedLists(leftSortedData, partitionedData.pivotNode, rigthSortedData);
}

Node* quickSort(Node* head) {
	utilContainerQuickSort answer = quickSortHelper(head);
	return answer.head;
}

int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=sJhUy4ixASE&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=32
	PREREQUISITE: "linked-list-move-last-index-element-such-that-left-is-smaller-and-right-is-larger"
	*/
	LinkedList ll;
	ll.addLast(5);
	ll.addLast(1);
	ll.addLast(2);
	ll.addLast(9);
	ll.addLast(5);
	ll.addLast(14);
	ll.addLast(11);
	ll.addLast(1);
	ll.addLast(10);
	ll.addLast(10);
	ll.addLast(1);
	ll.addLast(3);
	ll.printLinkedList();
	cout << "after quick sort: " << endl;
	Node* head = quickSort(ll.head);
	print(head);

}
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

void print(Node* head) {
	Node* temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* reverseIterative(Node* head) {
	//edge case --> is linked list is empty or of 1 size return head
	if (head == NULL or head->next == NULL) return head;

	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;

	while (curr) {
		next = curr->next; //backup
		curr->next = prev; //linking

		//move
		prev = curr;
		curr = next;
	}
	return prev;
}

Node* multiplyLinkedListWithSingleDigit(Node* head, int digit) {
	LinkedList ans;
	Node* curr = head;
	int carry = 0;

	while (curr) {
		// cout << "curr " << curr->data << endl;
		int sum = carry + (curr->data * digit);
		// cout << "sum " << sum << endl;
		int val = sum % 10;
		// cout << "val " << val << endl;

		ans.addLast(val);
		carry = sum / 10;
		// cout << "carry " << carry << endl;

		curr = curr->next;
	}
	if (carry != 0) {
		ans.addLast(carry);
	}
	return ans.head;
}

void addTwoLinkedList(Node* head, Node* ans) {
	Node* prod_Itr = head;
	Node* ans_Itr = ans;

	int carry = 0;
	while (prod_Itr or carry != 0) {
		int sum = carry + (prod_Itr != NULL ? prod_Itr->data : 0) + (ans_Itr->next != NULL ? ans_Itr->next->data : 0);
		//NOTE: ans_Itr->next se add kia, kyoki ek cross(X) lgana hota hai jab ham add krte hai multiply krte time(to do on pen paper)
		int digit = sum % 10;
		carry = sum / 10;

		//add digit in ans_itr(ans_Itr)
		if (ans_Itr->next != NULL) {
			ans_Itr->next->data = digit;
		}
		else {//create node
			ans_Itr->next = new Node(digit);
		}

		//move
		if (prod_Itr != NULL) prod_Itr = prod_Itr->next;
		ans_Itr = ans_Itr->next; //think ki kyo ans_Itr me NULL check nhi kia
	}
}

Node* multiplyTwoLinkedList(Node* l1, Node* l2) {
	//watch video recommended

	//reverse kro both linked list ko
	l1 = reverseIterative(l1);
	l2 = reverseIterative(l2);

	Node* l2_itr = l2;
	Node* dummy = new Node(-1);
	Node* ans_itr = dummy; //this is a dummy node, watch video recommended
	while (l2_itr) {
		Node* prod = multiplyLinkedListWithSingleDigit(l1, l2_itr->data);
		l2_itr = l2_itr->next;

		addTwoLinkedList(prod, ans_itr);
		ans_itr = ans_itr->next;
	}
	return reverseIterative(dummy->next); //coz, ansitr is a dummy node with data -1 toh next krne se actual node mil jaegi
}




int main()
{
	/*
	PREREQUISITE: addition of two linked list
	NOTE: please watch video for better understanding.
	VIDEO LINK: https://www.youtube.com/watch?v=I5uKH3BWsLc&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=24
	*/
	LinkedList l1;
	l1.addLast(1);
	l1.addLast(0);
	l1.addLast(0);

	cout << "number 1" << endl;
	l1.printLinkedList();

	LinkedList l2;
	l2.addLast(1);
	l2.addLast(8);

	cout << "number 2" << endl;
	l2.printLinkedList();

	Node* res = multiplyTwoLinkedList(l1.head, l2.head);
	cout << "after multiplication" << endl;
	print(res);
}
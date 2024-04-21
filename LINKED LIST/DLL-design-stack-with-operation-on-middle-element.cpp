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
public:
	Node* head;
	Node* mid;
	int size;

	DoublyLinkedList() {
		head = NULL;
		mid = NULL;
		size = 0;
	}

	void push(int data) {
		//insert at the head of DLL
		//i write this myself, you can WV
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			mid = newNode;
			size++;
		}

		else { //head is not NULL
			newNode->prev = head;
			head->next = newNode;
			head = newNode;
			size++;
			if (size % 2 == 0) { //even h, move mid by one
				mid = mid->next;
			}
			else { //odd h
				//mid will stay where it was.
			}
		}
		cout << "head " << head->data << " " << mid->data << endl;
	}

	void pop() {
		//i write this myself
		if (head == NULL) {
			cout << "empty" << endl;
		}
		else if (size == 1) { //means only one node is there
			head = NULL;
			mid = NULL;
			size--;
		}
		else {
			//this is like delete from head of a DLL
			Node* tobefreed = head;
			head = head->prev;

			// cout << "he " << head->data << endl;
			size--;
			if (size % 2 == 0) { //even size, no need to move mid

			}
			else {//odd aya, means mid ko one step peeche le jao
				mid = mid->prev;
			}
			free(tobefreed);
		}
	}

	int middle() {
		if (mid != NULL)
			return mid->data;
		else {
			cout << "middle not available" << endl;
			return -1;
		}
	}


};


int main()
{
	//VIDEO LINK: https://www.youtube.com/watch?v=ua1bPxSV_H0
	DoublyLinkedList ll;
	ll.push(1);
	ll.push(2);
	ll.push(3);
	cout << ll.middle() << endl;

	ll.pop();
	cout << ll.middle() << endl;

	ll.pop();
	cout << ll.middle() << endl;
}
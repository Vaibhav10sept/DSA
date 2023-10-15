#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* next;
	int data;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

void printLinkedList(Node* head) {
	Node* temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* removeElements(Node* head, int val) {
	//i wrote it no video, no reading.
	Node* temp = head;
	if (head == NULL) return NULL;
	while (temp) {
		if (temp->next and temp->next->data == val) {
			temp->next = temp->next->next;
		}
		else {
			temp = temp->next;
		}
	}

	if (head->data == val) return head->next;
	return head;
}


int main()
{
	/*
	NOTE: i wrote it myself, no video, no reading, all by myself.
	VIDEO:
	LEETCODE: https://leetcode.com/problems/remove-linked-list-elements/description/
	*/
	Node* head = new Node(0);
	Node* newNode;

	newNode = new Node(1);
	head->next = newNode;

	newNode = new Node(2);
	head->next->next = newNode;

	newNode = new Node(2);
	head->next->next->next = newNode;

	newNode = new Node(1);
	head->next->next->next->next = newNode;

	newNode = new Node(0);
	head->next->next->next->next->next = newNode;

	printLinkedList(head);
	head = removeElements(head, 2);
	cout << "after removal: " << endl;
	printLinkedList(head);
}
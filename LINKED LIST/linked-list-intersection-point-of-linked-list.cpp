#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* next;
	int data;
};

int getSize(Node* head) {
	int count = 0;
	Node* temp = head;
	while (temp) {
		count++;
		temp = temp->next;
	}
	return count;
}

int getIntesectionNode(Node* head1, Node* head2) {
	/*
	STEP:
	1. pehle first and second ko barabar le aao, means jiska size jyada hai usko diff jitna chla do
	2. fir, first and second ke ek step chlao jab tak dono equal nhi ho jate, equal hone par answer mil jaega
	*/
	Node* first = head1;
	Node* second = head2;
	int size1 = getSize(head1);
	int size2 = getSize(head2);

	if (size1 > size2) {
		int diff = size1 - size2;
		for (int i = 0; i < diff; i++) {
			first = first->next;
		}
	}
	else if (size2 > size1) {
		int diff = size2 - size1;
		for (int i = 0; i < diff; i++) {
			second = second->next;
		}
	}

	Node* ans = NULL;

	while (first && second) {
		if (first == second) {
			ans = first;
			break;
		}
		first = first->next;
		second = second->next;
	}
	return ans->data;
}

int main()
{
	//*********************************
	// NOTE: YOU CANNOT TEST THIS ONE ONLY FUNCTION IS WRITTEN
	// DON'T RUN IT CAUSE THE CODE TO RUN THIS FUNCTION IS
	// NOT WRITTEN.
	//************************************
	/*
	    Create two linked lists

	    1st 3->6->9->15->30
	    2nd 10->15->30

	    15 is the intersection point
	*/

	Node* newNode;

	// Addition of new nodes
	Node* head1 = new Node();
	head1->data = 10;

	Node* head2 = new Node();
	head2->data = 3;

	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;

	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	cout << "The node of intersection is " << getIntesectionNode(head1, head2);
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* next;
	int data;

	Node(int key) {
		data = key;
		next = NULL;
	}

	Node() {
		next = NULL;
	}
};

Node* newNode(int key)
{
	Node* temp = new Node(key);
	return temp;
}

void removeCyle(Node* meet, Node* head) {
	/*
	LOGIC: 1. ek pointer head(head) pe hoga
	2. doosra pointer intersection pointer pe hoga
	3. fir dono pointer ek step se move krege, jab ye dono pointers meet krege vo intersecting node hoga
	*/
	//this is confirm that ll has cycle, kyoki iss function ko call hi cycle detect hone pr kia hai
	Node* prev = meet;
	while (head != meet) {
		prev = meet;
		head = head->next;
		meet = meet->next;
	}
	//here, head == meet.
	prev->next = NULL;
	return;
}

void detectAndRemoveCycle(Node* head) {
	/*
	LOGIC: agr cycle hai toh fast and slow pointer will meet,
	otherwise fast pointer NULL ho jaega, means no cycle.
	watch video for intiution behind this.
	*/

	//edge case --> empty or one size ll, means no cycle, return false
	if (head == NULL or head->next == NULL) return;

	Node* slow = head;
	Node* fast = head;

	while (fast->next != NULL and fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) { //cycle found
			return removeCyle(slow, head);
		}
	}
	return; //no cycle
}

Node* findIntersectingNodeInCycle(Node* meet, Node* start) {
	/*
	LOGIC: 1. ek pointer head(start) pe hoga
	2. doosra pointer intersection pointer pe hoga
	3. fir dono pointer ek step se move krege, jab ye dono pointers meet krege vo intersecting node hoga
	*/
	//this is confirm that ll has cycle, kyoki iss function ko call hi cycle detect hone pr kia hai
	while (start != meet) {
		start = start->next;
		meet = meet->next;
	}
	//here, start == meet.
	return start;
}

Node* detectCycleAndReturnItersectionNode(Node* head) {
	/*
	LOGIC: agr cycle hai toh fast and slow pointer will meet,
	otherwise fast pointer NULL ho jaega, means no cycle.
	watch video for intiution behind this.
	*/

	//edge case --> empty or one size ll, means no cycle, return false
	if (head == NULL or head->next == NULL) return NULL;

	Node* slow = head;
	Node* fast = head;

	while (fast->next != NULL and fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) { //cycle found
			return findIntersectingNodeInCycle(slow, head);
		}
	}
	return NULL; //no cycle
}


bool detectCycle(Node* head) {
	/*
	LOGIC: agr cycle hai toh fast and slow pointer will meet,
	otherwise fast pointer NULL ho jaega, means no cycle.
	watch video for intiution behind this.
	*/

	//edge case --> empty or one size ll, means no cycle, return false
	if (head == NULL or head->next == NULL) return false;

	Node* slow = head;
	Node* fast = head;

	while (fast->next != NULL and fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) { //cycle found
			// return findIntersectingNodeInCycle(slow, ll.head);
			return true;
		}
	}
	return false; //no cycle
}

int main()
{
	/*
	NOTE: THIS IS ALL IN ONE QUESTION IT HAS EVERY PROBLEM RELATED TO LOOP/CYCLE IN LINKED LIST
	LIKE: 1. DETECT CYCLE
	2. FIND JUNCTION NODE
	3. REMOVE CYCLE
	NOTE: this is "floyd's cycle detection algorithm"
	NOTE: slow and fast pointer approch is used here.
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=jcZtMh_jov0
	LEETCODE LINK: https://leetcode.com/problems/linked-list-cycle/
	*/
	Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	cout << "has cycle: " << detectCycle(head) << endl;

	Node* intersectionNode = detectCycleAndReturnItersectionNode(head);
	if (intersectionNode != NULL) { //cycle hai
		cout << "linkedList has cycle with junction at: " << intersectionNode->data << endl;
	}

	cout << "after removing cycle" << endl;
	detectAndRemoveCycle(head);
	cout << "has cycle: " << detectCycle(head) << endl;

}
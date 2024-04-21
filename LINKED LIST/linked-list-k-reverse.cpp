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

Node* reverseRecursive(Node* head, int k) {
	// base case
	if (head == NULL) return NULL;

	//check if there are "k" nodes to be reversed
	Node* temp = head;
	int nodeCount = 0;
	while (temp) {
		temp = temp->next;
		nodeCount++;
	}

	if (nodeCount < k) return head; //no need to reverse.

	Node* current = head;
	Node* next = NULL;
	Node* prev = NULL;
	int count = 1;

	/*reverse first k nodes of the linked list, using the iterative linked list reverse method already done before do check if you have doubts */
	while (current != NULL && count <= k) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	/* next is now a pointer to (k+1)th node
	   NOTE: next and current both are in same node, so use can also use current instead of next.
	Recursively call for the list starting from current.
	And make rest of the list as next of first node */
	if (next != NULL) {
		//head will be the new last so, head->next pe lagega jo result aega recursize call ke baad
		head->next = reverseRecursive(next, k);
	}

	/* prev is new head of the input list */
	return prev;
}

Node* reverseIterative(Node* node, int k) {
	// this is written by me.
	LinkedList res;
	while (node) {
		stack<Node*> st;

		for (int i = 1; i <= k && node; i++) {
			st.push(node);
			node = node->next;
		}

		//if there are "k" nodes then only reverse them
		if (st.size() == k) {
			while (!st.empty()) {
				res.addLast(st.top()->data);
				st.pop();
			}
		}
		//else, if there are not "k" nodes in the stack then add then in there original sequence no need to reverse.
		else {
			vector<int> temp;
			while (!st.empty()) {
				temp.push_back(st.top()->data);
				st.pop();
			}
			reverse(temp.begin(), temp.end());
			for (auto ele : temp) {
				res.addLast(ele);
			}
		}
	}
	return res.head;
}

int main()
{
	// 	blueprint of recursive method:
	// 1. check if there are "k" nodes to be reversed using a while loop if count is less then k then don't reverse just return the head(passed as argument).
	// 2. reverse first k nodes of the linked list, using the iterative linked list reverse method already done before do check if you have doubts
	// 3. now, k length list is reversed, next is now a pointer to (k+1)th node, so do the recursive call passing next and take the result in head->next(as head has now become the tail of k sized linked list).
	// 4. return the prev pointer as it will be the next head of k size reversed linked list.
	int k = 3;
	cout << "original linked list:" << endl;
	LinkedList ll;
	ll.addFirst(7);
	ll.addFirst(6);
	ll.addFirst(5);
	ll.addFirst(4);
	ll.addFirst(3);
	ll.addFirst(2);
	ll.addFirst(1);
	ll.addFirst(0);
	ll.printLinkedList();
	ll.head = reverseRecursive(ll.head, k);
	cout << "recursive reverse k result:" << endl;
	ll.printLinkedList();
	LinkedList ll2;
	ll2.addFirst(7);
	ll2.addFirst(6);
	ll2.addFirst(5);
	ll2.addFirst(4);
	ll2.addFirst(3);
	ll2.addFirst(2);
	ll2.addFirst(1);
	ll2.addFirst(0);
	ll2.head = reverseIterative(ll2.head, k);
	cout << "iterative reverse k result:" << endl;
	ll2.printLinkedList();
}
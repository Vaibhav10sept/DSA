#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node* prev;
	int data;
	Node(int d) {
		data = d;
		prev = NULL;
	}
};

class LinkedList
{
public:
	Node* tail;
	int size;

	LinkedList() {
		tail = NULL;
		size = 0;
	}

	void helperRecursive(Node* temp) {
		if (temp == NULL) return; //base case

		helperRecursive(temp->prev);
		cout << temp->data << " ";
	}

	printInReverseRecursive() {
		Node* temp = tail;
		helperRecursive(temp);
	}
};

void multiply(LinkedList &ll, int n) {
	int carry = 0;
	Node* temp = ll.tail;
	Node* prevNode = ll.tail;

	while (temp != NULL) {
		int data = temp->data;
		int mul = data * n;
		mul += carry;
		temp->data = mul % 10;
		carry = mul / 10;
		prevNode = temp;
		temp = temp->prev;
	}

	while (carry != 0) {
		Node* newNode = new Node(carry % 10);
		carry = carry / 10;
		prevNode->prev = newNode;
		ll.size++;
	}

}

void factorialOfLargeNumber(int n) {
	LinkedList ll;
	Node* newNode = new Node(1);
	ll.tail = newNode;
	ll.size = 1;
	int num = 1;
	while (num <= n) {
		multiply(ll, num);
		num++;
	}

	ll.printInReverseRecursive();
}


int main()
{
	/*
	PREREQUISITE: basic of linked list
	VIDOE LINK: https://www.youtube.com/watch?v=VCfZOe1oJHU
	QUESTION LINK: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
	*/
	int n = 1000;
	factorialOfLargeNumber(n);
}
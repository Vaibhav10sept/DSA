#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
	ListNode* next;
	int val;

	ListNode(int data) {
		val = data;
		next = NULL;
	}
};

void printLL(ListNode* node) {

	while (node) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}

ListNode* findMid(ListNode* node) {
	ListNode* fast = node;
	ListNode* slow = node;

	while (fast->next and fast->next->next) {
		slow =  slow->next;
		fast = fast->next->next;
	}

	return slow;
}

ListNode* reverseLinkedListIterative(ListNode* node) {
	ListNode* curr = node;
	ListNode* prev = NULL;
	ListNode* next = NULL;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev; //this is the new head;
}

ListNode* reorderList(ListNode* head) {
	// NOTE: this is my code, no video, no reading
	ListNode* mid = findMid(head);
	ListNode* head2 = reverseLinkedListIterative(mid->next);
	mid->next = NULL;
	// cout << "mid " << mid->val << endl;
	// printLL(head2);
	ListNode* temp = head;
	while (temp and head2) {
		ListNode* next = temp->next;
		temp->next = head2;
		ListNode* next2 = head2->next;
		head2->next = next;
		temp = next;
		head2 = next2;
	}

	return head;
}


int main()
{
	/*
	NOTE: this is my code, no video, no reading
	VIDEO LINK: no khud se kia h
	LINK: https://leetcode.com/problems/reorder-list/description/
	PREREQUISITE:
	*/
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	cout << "before" << endl;
	printLL(head);
	head = reorderList(head);
	cout << "after" << endl;
	printLL(head);
}
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
	ListNode* next;
	ListNode* random;
	int data;

	ListNode(int val) {
		data = val;
		next = NULL;
		random = NULL;
	}

	ListNode() {
		next = NULL;
		random = NULL;
	}
};

LinkedList CopyListWithRandomPointers(LinkedList ll) {
	//this code is copied from leetcode
	map<ListNode*, ListNode*> m;
	//m.first --> original list ka pointer
	//m.second --> deep copied list ka pointer.
	ListNode* ptr = head;
	while (ptr) {
		m[ptr] = new ListNode(ptr->val);
		ptr = ptr->next;
	}
	ptr = head;
	while (ptr) {
		m[ptr]->next = m[ptr->next];
		m[ptr]->random = m[ptr->random];
		ptr = ptr->next;
	}
	return m[head];
}

int main()
{
	/*
	NOTE: THIS QUESTION CANNOT BE EXECUTED.
	NOTE: more space(constant space) optimized sol of this is their just search
	NOTE: we use map here.
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=deaZgauZVco&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=14
	LEETCODE LINK: https://leetcode.com/problems/copy-list-with-random-pointer/
	*/
	cout << "this question cannot be executed, as the test case is not there" << endl;
}
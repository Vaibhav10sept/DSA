#include <bits/stdc++.h>
using namespace std;


class LRUCache {
public:
	class node {
	public:
		int key;
		int val;
		node* next;
		node* prev;
		node(int _key, int _val) {
			key = _key;
			val = _val;
			next = NULL;
			prev = NULL;
		}
	};

	node* head = new node(-1, -1); //most recently used
	node* tail = new node(-1, -1); //least recently used

	int cap; //capacity
	unordered_map<int, node*> m;

	LRUCache(int capacity) {
		cap = capacity;
		head->next = tail;
		tail->prev = head;
	}

	void addnode(node* newnode) {
		// add at the head, most recently used
		node* temp = head->next;
		newnode->next = temp;
		newnode->prev = head;
		head->next = newnode;
		temp->prev = newnode;
	}

	void deletenode(node* delnode) {
		node* delprev = delnode->prev;
		node* delnext = delnode->next;
		delprev->next = delnext;
		delnext->prev = delprev;
	}

	int get(int key_) {
		if (m.find(key_) != m.end()) {
			node* resnode = m[key_];
			int res = resnode->val;
			m.erase(key_);
			deletenode(resnode);
			addnode(resnode); //add at head, so it become the most recently used
			m[key_] = head->next;
			return res;
		}

		return -1;
	}

	void put(int key_, int value) {
		if (m.find(key_) != m.end()) { //key found
			node* existingnode = m[key_];
			m.erase(key_);
			deletenode(existingnode);
		}
		if (m.size() == cap) {
			m.erase(tail->prev->key); // delete the node at tail from the map
			deletenode(tail->prev); //delete the node at tail, least recently used node
		}

		addnode(new node(key_, value)); //add at head
		m[key_] = head->next; // adding in map
	}
};

int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=xDEuM5qa0zg
	LEETCODE LINK: https://leetcode.com/problems/lru-cache/
	*/
	int capacity = 2;
	LRUCache obj(capacity);
	obj.put(1, 1);
	obj.put(2, 2);
	cout << obj.get(1) << endl; //1
	obj.put(3, 3);
	cout << obj.get(2) << endl; //-1
	obj.put(4, 4);
	cout << obj.get(1) << endl; //-1
	cout << obj.get(3) << endl; //3
	cout << obj.get(4) << endl; //4

}
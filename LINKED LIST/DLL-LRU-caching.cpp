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
	unordered_map<int, node*> m; //key->DLL node pointer(address)

	LRUCache(int capacity) {
		cap = capacity;
		head->next = tail;
		tail->prev = head;
	}

	void addNodeAtHead(node* newnode) {
		// add at the head, most recently used
		//time: o(1)
		node* temp = head->next;
		newnode->next = temp;
		newnode->prev = head;
		head->next = newnode;
		temp->prev = newnode;
	}

	void deleteNode(node* delnode) {
		//time: o(1)
		node* delprev = delnode->prev;
		node* delnext = delnode->next;
		delprev->next = delnext;
		delnext->prev = delprev;
	}

	int get(int key_) {
		if (m.find(key_) != m.end()) { //means found
			//note: is this case we have delete the node form map and doubly linked list both
			//and then add in the head of DLL(to make it most recently used) and also in the map
			node* resnode = m[key_];
			int res = resnode->val;
			m.erase(key_);
			deleteNode(resnode);
			addNodeAtHead(resnode); //add at head, so it become the most recently used
			m[key_] = head->next;
			return res;
		}

		return -1; //not found so return -1
	}

	void put(int key_, int value) {
		if (m.find(key_) != m.end()) { //key found
			node* existingnode = m[key_];
			//delete krna h kyoki, hme ab iss node ko most recently used bnana pdega so delete and add at the head of DLL
			m.erase(key_);
			deleteNode(existingnode);
		}
		if (m.size() == cap) {
			//here, we are deleting the least recently used node(tail node)
			m.erase(tail->prev->key); // delete the node(from map) and at tail(from DLL) from the map
			deleteNode(tail->prev); //delete the node at tail(from DLL), least recently used node
		}

		addNodeAtHead(new node(key_, value)); //add at head(most recently used)
		m[key_] = head->next; // adding in map
	}
};

int main()
{
	/*
	SIMILAR: LFU caching
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
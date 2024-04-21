#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key, value, freq;
	Node *next;
	Node *prev;
	Node(int _key, int _value) {
		key = _key;
		value = _value;
		freq = 1; //this is the default freq of this node
	}
};
struct List {
	int size;
	Node *head;
	Node *tail;
	List() {
		head = new Node(0, 0);
		tail = new Node(0, 0);
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	void addFront(Node *node) {
		Node* temp = head->next;
		node->next = temp;
		node->prev = head;
		head->next = node;
		temp->prev = node;
		size++;
	}

	void removeNode(Node* delnode) {
		Node* delprev = delnode->prev;
		Node* delnext = delnode->next;
		delprev->next = delnext;
		delnext->prev = delprev;
		size--;
	}
};

class LFUCache {
	map<int, Node*> keyNode; // key --> Node*
	map<int, List*> freqListMap; // frequency --> doubly linked list(same as in LRU caching)
	int maxSizeCache;
	int leastFreq;

public:
	LFUCache(int capacity) {
		maxSizeCache = capacity;
		leastFreq = 0;
	}

	void updateFreqListMap(Node *node) {
		//remove from the keyNode and freqListMap
		keyNode.erase(node->key);
		freqListMap[node->freq]->removeNode(node);

		if (node->freq == leastFreq && freqListMap[node->freq]->size == 0) {
			leastFreq++;
		}

		List* nextHigherFreqList = new List();
		if (freqListMap.find(node->freq + 1) != freqListMap.end()) { //found
			nextHigherFreqList = freqListMap[node->freq + 1];
		}
		node->freq += 1;
		nextHigherFreqList->addFront(node);
		freqListMap[node->freq] = nextHigherFreqList;
		keyNode[node->key] = node;
	}

	int get(int key) {
		if (keyNode.find(key) != keyNode.end()) { //found
			Node* node = keyNode[key];
			int val = node->value;
			updateFreqListMap(node);
			return val;
		}
		return -1;
	}

	void put(int key, int value) {
		if (maxSizeCache == 0) {
			return;
		}
		if (keyNode.find(key) != keyNode.end()) { //found --> update krdo
			Node* node = keyNode[key];
			node->value = value;
			updateFreqListMap(node);
		}
		else {  //not found --> insert krdo, agr capacity full hogae toh LFU ko remove krke isko insert krdo
			if (keyNode.size() == maxSizeCache) { //now, remove the min freq + LRU node
				List* list = freqListMap[leastFreq];
				keyNode.erase(list->tail->prev->key); //DLL ki last node hi LRU node hoti h, to use remove krre from keyNode map
				freqListMap[leastFreq]->removeNode(list->tail->prev);
			}
			// new value has to be added who is not there previously
			leastFreq = 1; //rem: agr new node add ho rhi to least freq 1 hojaegi, ise update krna mt bhulna
			List* listFreq = new List();
			if (freqListMap.find(leastFreq) != freqListMap.end()) { //found
				listFreq = freqListMap[leastFreq];
			}
			Node* node = new Node(key, value);
			listFreq->addFront(node);
			keyNode[key] = node;
			freqListMap[leastFreq] = listFreq; //here, leastFreq is 1(upper code dekho, cs)
		}
	}
};
/*
STRONG PREQ: LRU caching
VIDEO: https://www.youtube.com/watch?v=0PSB9y8ehbk
LEETCODE: https://leetcode.com/problems/lfu-cache/
*/


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
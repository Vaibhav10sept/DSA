#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
private:
	int head, tail, size, capacity;
	vector<int> q;
public:
	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k) : head(0), tail(0), capacity(k), size(0), q(vector<int>(k, 0)) {}

	bool insertFront(int value) {
		if (isFull()) return false;
		head = head == 0 ? capacity - 1 : head - 1;
		q[head] = value;
		size++;
		return true;
	}

	bool insertLast(int value) {
		if (isFull()) return false;
		q[tail++] = value;
		tail %= capacity;
		size++;
		return true;
	}

	bool deleteFront() {
		if (isEmpty()) return false;
		head = (head + 1) % capacity;
		size--;
		return true;
	}

	bool deleteLast() {
		if (isEmpty()) return false;
		tail = tail == 0 ? capacity - 1 : tail - 1;
		size--;
		return true;
	}

	int getFront() {
		return isEmpty() ? -1 : q[head];
	}

	int getRear() { //ye doubtfull hai.(think, exceptional case)
		return isEmpty() ? -1 : tail == 0 ? q[capacity - 1] : q[tail - 1];
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}

};

int main()
{
	/*
	NOTE: cannot run this question submit it on leetcode to run
	NOTE: this code is copied from leetcode discussion
	LEETCODE: https://leetcode.com/problems/design-circular-deque/
	*/
	vector<int> arr = {1, 2, 3, 4, 5, 6};
	print(arr);
}
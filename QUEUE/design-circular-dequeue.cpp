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
		q[tail] = value;
		tail++;
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

	int getRear() { //think, tail hmesa ek step age rhta as compared to head jo head vali value pe hi hota h
		//so, to get the tail value hm tail ke ek peeche dekhte h.
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
	NOTE: tail or head me ek diff h or vo diff kyo rhka gya h iske bare me sochna
	//diff ye h ki head, head vali value pe hi hota h balki tail, tail vali value se ek age hota h, islie getTail() me hm tail ko ek peeche krke tail value find krte h
	LEETCODE: https://leetcode.com/problems/design-circular-deque/
	*/
	MyCircularDeque obj(3);
	cout << obj.insertLast(1) << endl;
	cout << obj.insertLast(2) << endl;
	cout << obj.insertFront(3) << endl;
	cout << obj.insertFront(4) << endl;
	cout << obj.getRear() << endl;
	cout << obj.isFull() << endl;
	cout << obj.deleteLast() << endl;
	cout << obj.insertFront(4) << endl;
	cout << obj.getFront() << endl;

}
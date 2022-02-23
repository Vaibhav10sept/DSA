#include <bits/stdc++.h>
using namespace std;

class MedianPriorityQueue {
public:
	priority_queue<int> left; // max priority queue
	priority_queue<int, vector<int>, greater<int>> right; // min priority queue
	// note: left will hold the smaller half of the array
	// while right will hold the greater half of the array.
	// difference of size of both priority queue cannot be more than 1.
	// by default we add and remove from left(if size of both queues is equal).
	int size() {
		return left.size() + right.size();
	}
	void add(int data) {
		if (right.size() > 0 and data > right.top()) {
			right.push(data);
		}
		else {
			left.push(data);
		}
		//balancing: to keep the difference of size of both priority queue not more than 1.
		if (left.size() - right.size() == 2) {
			right.push(left.top());
			left.pop();
		}
		else if (right.size() - left.size() == 2) {
			left.push(right.top());
			right.pop();
		}
	}

	int peekMedian() {
		if (this->size() == 0) {
			cout << "underflow " << endl;
			return -1;
		}
		if (left.size() >= right.size()) {
			return left.top();
		}
		else {
			return right.top();
		}
	}

	void removeMedian() { // this will remove the median.
		if (this->size() == 0) {
			cout << "underflow " << endl;
			return;
		}
		if (left.size() >= right.size()) {
			return left.pop();
		}
		else {
			return right.pop();
		}
	}
};

int main() {
	MedianPriorityQueue obj;
	obj.add(10);
	obj.add(20);
	obj.add(30);
	obj.add(40);
	obj.add(50);
	cout << "size " << obj.size() << endl;
	cout << obj.peekMedian() << endl;
	obj.removeMedian();
	cout << obj.peekMedian() << endl;
	obj.removeMedian();
	cout << obj.peekMedian() << endl;
}
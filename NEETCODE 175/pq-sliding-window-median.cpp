#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
	//nice question, easy logic, WV
	priority_queue<int> smallHeap; //max heap
	priority_queue<int, vector<int>, greater<int>> largeHeap; //min heap
	MedianFinder() {

	}

	void addNum(int num) {
		// always add num in small heap and then perform the operation
		// 1. make the size diff of large and small heap <= 1.
		// 2. all elements in small heap <= all elements in large heap.
		smallHeap.push(num);

		//make sure every element in small heap <= every element in large heap
		if (!smallHeap.empty() and !largeHeap.empty() and smallHeap.top() > largeHeap.top()) {
			//voilation hua
			//pop the max from small heap(max heap) and add it to the large heap(min heap)
			largeHeap.push(smallHeap.top());
			smallHeap.pop();
		}

		//make the size diff of both the heap <= 1
		if (smallHeap.size() > largeHeap.size() + 1) {
			//small heap se nikal ke large heap me daal do
			largeHeap.push(smallHeap.top());
			smallHeap.pop();
		}
		if (largeHeap.size() > smallHeap.size() + 1) {
			// large heap se nikal ke small heap me daal do
			smallHeap.push(largeHeap.top());
			largeHeap.pop();
		}
	}

	double findMedian() { // TIME: O(1)
		if (smallHeap.size() > largeHeap.size()) {
			return (double)smallHeap.top();
		}
		else if (largeHeap.size() > smallHeap.size()) {
			return (double)largeHeap.top();
		}
		else { //smallHeap.size() == largeHeap.size()
			return (double)(smallHeap.top() + largeHeap.top()) / 2;
		}
	}
};

int main() {
	/*********************************
	LOGIC: we use two priority queue here
	1. small heap --> this is max heap
	2. large heap --> this is min heap
	NOTE: all elements in small heap <= all elements in large heap
	      size of small and large heap can vary by at most 1.
	TIME: add/remove from heap --> logn
	  	  get the min/max element from min/max heap --> O(1)
	VIDEO LINK: https://www.youtube.com/watch?v=itmhHWaHupI
	LEETCODE LINK: https://leetcode.com/problems/find-median-from-data-stream/https://leetcode.com/problems/design-twitter/
	*********************************/
	MedianFinder obj;
	obj.addNum(1);
	obj.addNum(2);
	cout <<	obj.findMedian() << endl;
	obj.addNum(3);
	cout << obj.findMedian() << endl;

}
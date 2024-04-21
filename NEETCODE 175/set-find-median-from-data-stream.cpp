#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
	std::multiset<int> smallHeap; // max heap
	std::multiset<int> largeHeap; // min heap

	MedianFinder() {

	}

	void addNum(int num) {
		// Always add 'num' in smallHeap and then perform the operation.
		// 1. Ensure the size difference of largeHeap and smallHeap is <= 1.
		// 2. Ensure all elements in smallHeap are less than or equal to all elements in largeHeap.
		smallHeap.insert(num);

		// Ensure that every element in smallHeap is less than or equal to every element in largeHeap.
		if (!smallHeap.empty() && !largeHeap.empty() && *(smallHeap.rbegin()) > *(largeHeap.begin())) {
			// Violation occurred.
			// Pop the maximum from smallHeap (max heap) and add it to largeHeap (min heap).
			largeHeap.insert(*(smallHeap.rbegin()));
			//erase by iterator not by value, coz erase by value delete all occurences but we want to delete only the specific value
			smallHeap.erase(--smallHeap.end()); //this will not the value at the iterator point, not all occurences.
		}

		// Ensure the size difference of both heaps is <= 1.
		if (smallHeap.size() > largeHeap.size() + 1) {
			// Move the maximum element from smallHeap to largeHeap.
			largeHeap.insert(*(smallHeap.rbegin()));
			smallHeap.erase(--smallHeap.end());
		} else if (largeHeap.size() > smallHeap.size() + 1) {
			// Move the minimum element from largeHeap to smallHeap.
			smallHeap.insert(*(largeHeap.begin()));
			largeHeap.erase(largeHeap.begin());
		}
	}

	double findMedian() { // TIME: O(1)
		if (smallHeap.size() > largeHeap.size()) {
			return static_cast<double>(*(smallHeap.rbegin()));
		} else if (largeHeap.size() > smallHeap.size()) {
			return static_cast<double>(*(largeHeap.begin()));
		} else { // smallHeap.size() == largeHeap.size()
			return static_cast<double>(*(smallHeap.rbegin()) + * (largeHeap.begin())) / 2.0;
		}
	}
};

int main() {
	/*********************************
	 * NOTE: this is set sol a pq sol is also there.
	LOGIC: we use two priority queue here
	1. small heap --> this is max heap
	2. large heap --> this is min heap
	NOTE: all elements in small heap <= all elements in large heap
	      size of small and large heap can vary by at most 1.
	TIME: add/remove from heap --> logn
	  	  get the min/max element from min/max heap --> O(1)
	VIDEO LINK: https://www.youtube.com/watch?v=itmhHWaHupI
	LEETCODE LINK: https://leetcode.com/problems/find-median-from-data-stream/
	*********************************/
	MedianFinder obj;
	obj.addNum(-1);
	cout <<	obj.findMedian() << endl;
	obj.addNum(-2);
	cout <<	obj.findMedian() << endl;
	obj.addNum(-3);
	cout << obj.findMedian() << endl;
	obj.addNum(-4);
	cout <<	obj.findMedian() << endl;
	obj.addNum(-5);
	cout <<	obj.findMedian() << endl;

}
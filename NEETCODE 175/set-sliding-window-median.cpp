#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
	multiset<long long> smallHeap; // max heap
	multiset<long long> largeHeap; // min heap

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

	void removeValue(int value) {
		// To remove a specific value
		auto it = smallHeap.find(value);
		if (it != smallHeap.end()) {
			smallHeap.erase(it);
		} else {
			it = largeHeap.find(value);
			if (it != largeHeap.end()) {
				largeHeap.erase(it);
			}
		}
	}
};

vector<double> medianSlidingWindow(vector<int>& arr, int k) {
	// * NOTE: i wrote this after taking help from set find median from data stream
	vector<double> result;
	MedianFinder obj;

	//sliding window
	int i = 0;
	int j = 0;
	int n = arr.size();
	while (j < n) {
		obj.addNum(arr[j]);
		if (j - i + 1 == k) {
			result.push_back(obj.findMedian());

			obj.removeValue(arr[i]);
			i++;
		}
		j++;
	}

	return result;
}

int main() {
	/*********************************
	 * NOTE: i wrote this after taking help from set find median from data stream
	 * NOTE: we use set here not priority queue.
	 * STRONG PREQ: set find median from data stream
	LOGIC: we use two priority queue here
	1. small heap --> this is max heap
	2. large heap --> this is min heap
	NOTE: all elements in small heap <= all elements in large heap
	      size of small and large heap can vary by at most 1.
	TIME: add/remove from heap --> logn
	  	  get the min/max element from min/max heap --> O(1)
	VIDEO LINK: https://www.youtube.com/watch?v=itmhHWaHupI
	LEETCODE LINK: https://leetcode.com/problems/sliding-window-median/description/
	*********************************/
	vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;
	vector<double> medians = medianSlidingWindow(nums, k);

	for (double median : medians) {
		cout << median << " ";
	}
	cout << endl;

}
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
	int largestIndex = i;
	int leftChildIdx = i * 2 + 1;
	int rightChildIdx = i * 2 + 2;

	if (leftChildIdx < n and arr[leftChildIdx] > arr[largestIndex]) {
		largestIndex = leftChildIdx;
	}
	if (rightChildIdx < n and arr[rightChildIdx] > arr[largestIndex]) {
		largestIndex = rightChildIdx;
	}
	if (largestIndex != i) {
		swap(arr[i], arr[largestIndex]);
		//recursive call to heapify
		heapify(arr, n, largestIndex);
	}
}

void heapSort(vector<int> &arr) {
	//STEPS: 1. swap 0th element with the last element
	//       2. size--
	//       3. root node me jo element dala h use shi position me pahucha do.


	int size = arr.size();
	while (size > 1) {
		//step1
		swap(arr[0], arr[size - 1]); //now, max element last index me aa chuka h

		//step2
		size--;

		//step3
		heapify(arr, size, 0);
	}
}



int main() {
	/*
	NOTE: here we are following 0 based indexing, so read below note.
	NOTE: if we want to follow 0 based indexing then use leftChildIdx = 2*i + 1 and rightChildIdx = 2*i + 2;
	PREREQUISITE: heapify, max heap implementation
	USED IN: heap sort
	TIME: nlogn
	NOTE: heapify: means converts and array to heap.
	NOTE: array ko 1st index se start krege, 0th index se ni coz, child idx is 2*i, agr i 0 hoga to 2*i bhi 0 aega, which is wrong 0th idx ka child 0th idx ni ho skta.
	NOTE: we use max heap for heap sort to sort in increasing order
	VIDEO LINK: https://www.youtube.com/watch?v=NKJnHewiGdc
	*/
	vector<int> arr = {54, 53, 55, 52, 50};
	//NOTE: n/2 is the number of leaf nodes.
	//logic: leaf node is already heap, so in a heap from index 1 -> n, (n/2)+1 -> n index ke node leaf nodes hote h(dry run, think)
	//       that means ki hme leaf node ke liye heapify chlane ki jrurt ni to hm n/2 -> 1 index ke element ke liye hi heapify call krege.
	// 0th me dummy -1 data pda hua h, hm 1th index se start krege.
	int n = arr.size(); //-1 coz, 0th index ko consider ni krre.
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	//now, heap array is created. do heap sort for this array
	heapSort(arr);

	//print increasing sorted array after performing heap sort.
	cout << "sorted array" << endl;
	for (auto ele : arr) {
		cout << ele << " ";
	}
	cout << endl;
}
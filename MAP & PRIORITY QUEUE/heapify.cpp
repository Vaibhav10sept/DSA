#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
	// NOTE: here we are following 0 based indexing, so read below note.
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

int main() {
	/*
	NOTE: here we are following 0 based indexing, so read below note.
	NOTE: if we want to follow 0 based indexing then use leftChildIdx = 2*i + 1 and rightChildIdx = 2*i + 2;
	PREREQUISITE: max heap implementation
	USED IN: heap sort
	TIME of 1 heapify operation: logn
	TIME of building the array to heap using heapify: n
	NOTE: heapify: means converts an array to heap.
	NOTE: array ko 1st index se start krege, 0th index se ni coz, child idx is 2*i, agr i 0 hoga to 2*i bhi 0 aega, which is wrong 0th idx ka child 0th idx ni ho skta.
	NOTE: this is max heap implemenation
	VIDEO LINK: https://www.youtube.com/watch?v=UVW0NfG_YWA
	*/
	vector<int> arr = {54, 53, 55, 52, 50};
	// 55 53 54 52 50
	//NOTE: n/2 is the number of leaf nodes.
	//logic: leaf node is already heap, so in a heap from index 1 -> n, (n/2)+1 -> n index ke node leaf nodes hote h(dry run, think)
	//       that means ki hme leaf node ke liye heapify chlane ki jrurt ni to hm n/2 -> 1 index ke element ke liye hi heapify call krege.
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
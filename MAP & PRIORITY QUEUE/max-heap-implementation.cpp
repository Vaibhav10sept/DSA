#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
	vector<int> arr;
	int size;

	Heap() {
		arr.resize(1);
		// NOTE: array ko 1st index se start krege, 0th index se ni coz, child idx is 2*i, agr i 0 hoga to 2*i bhi 0 aega, which is wrong 0th idx ka child 0th idx ni ho skta.
		arr[0] = -1;
		size = 0;
	}

	void insert(int val) { //time: logn
		arr.push_back(val);
		size++;
		int idx = size; //arr starts from 1th index not from 0th index

		while (idx >= 1) {
			int parentIdx = idx / 2;
			if (parentIdx >= 1 and arr[parentIdx] < arr[idx]) {
				swap(arr[parentIdx], arr[idx]);
			}
			else { //means age check krne ki jrurt ni h.(think) this is for code optimization
				return;
			}
			idx = parentIdx;
		}
	}

	void deleteFromHeap() { //time: logn
		//  NOTE: this will delete the max value in the heap that is the root node.
		// STEP: 1. swap root node with the last node.
		//       2. remove last node
		//       3. propogate/heapify(make heap) the newly added root node, to its correct place.

		//edge case
		if (size == 0) {
			cout << "nothing to delete" << endl;
			return;
		}

		//step 1.
		swap(arr[0], arr[size]); //arr starts from 1th index not from 0th index

		//step 2.
		arr.pop_back();
		size--;

		//step 3.
		int idx = 1; //0th index me kuch ni h, index starts from 1
		while (idx >= size) {
			int leftChildIdx = 2 * idx;
			int rightChildIdx = 2 * idx + 1;

			//REM: we are making max heap
			if (arr[leftChildIdx] <= size and arr[leftChildIdx] > arr[idx]) {
				swap(arr[leftChildIdx], arr[idx]);
				idx = leftChildIdx;
			}
			else if (arr[rightChildIdx] <= size and arr[rightChildIdx] > arr[idx]) {
				swap(arr[rightChildIdx], arr[idx]);
				idx = rightChildIdx;
			}
			else {
				//means ki array already heap h, that means no need to check further, we can return from here, this is done to optimize code(think, CS)
				return;
			}
		}
	}

	void print() {
		for (int i = 1; i <= size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	/*
	NOTE: if we want to follow 0 based indexing then use leftChildIdx = 2*i + 1 and rightChildIdx = 2*i + 2;
	SIMILAR: heapify, heap sort
	NOTE: array ko 1st index se start krege, 0th index se ni coz, child idx is 2*i, agr i 0 hoga to 2*i bhi 0 aega, which is wrong 0th idx ka child 0th idx ni ho skta.
	NOTE: this is max heap implemenation
	VIDEO LINK: https://www.youtube.com/watch?v=NKJnHewiGdc
	TIME: insertion: logn
		  deletion: logn
	*/
	Heap obj;
	obj.insert(14);
	obj.insert(12);
	obj.insert(19);
	obj.insert(16);
	obj.insert(11);
	obj.print();

	obj.deleteFromHeap(); //this will delete the max value in the heap that is the root node.
	obj.print();
}
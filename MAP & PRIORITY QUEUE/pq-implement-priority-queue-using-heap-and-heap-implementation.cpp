#include <bits/stdc++.h>
using namespace std;

class priorityQueue {
public:
	vector<int> data;

	int size() {
		return data.size();
	}

	void upHeapify(int childidx) {
		if (childidx == 0) return; // base case
		int parentidx = (childidx - 1) / 2;
		if (data[parentidx] > data[childidx]) {
			swap(data[parentidx], data[childidx]);
			// recursive call
			upHeapify(parentidx);
		}
	}

	void push(int val) { // UPHEAPIFY(LOGN)
		data.push_back(val);
		upHeapify(data.size() - 1);
	}

	int top() { //O(1)
		if (this->size() == 0) { // O(1)
			cout << "underflow" << endl;
			return -1;
		}
		return data[0];
	}

	void downHeapify(int parentidx) {
		int leftidx = (parentidx * 2) + 1;
		int righidx = (parentidx * 2) + 2;
		int minidx = parentidx;
		if (leftidx < data.size() and data[leftidx] < data[parentidx]) {
			minidx = leftidx;
		}
		if (righidx < data.size() and data[righidx] < data[minidx]) {
			minidx = righidx;
		}
		if (minidx != parentidx) {
			swap(data[minidx], data[parentidx]);
			// recursive call(there is no base case think about it)
			downHeapify(minidx);
		}
	}
	void pop() { // DOWNHEAPIFY(LOGN)
		// 1. swap 0th index with the last index
		// 2. remove the last index(O(1))
		// 3. perform downheapify(from root to down the tree)
		if (this->size() == 0) {
			cout << "underflow" << endl;
			return;
		}
		swap(data[0], data[data.size() - 1]); //step 1
		data.pop_back();//step 2

		//3. perform downheapify
		downHeapify(0);
	}
};

int main() {
	// video Link: https://www.youtube.com/watch?v=RIjxT24gUv4&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=475
	// TIME COMPLEXITIES:
	// PUSH: LOGN
	// POP: LOGN
	// TOP: 1
	// HEAP DATA STRUCTURE:
	// 1. HEAP IS A COMPLETE  BINARY TREE
	// 2. PARENT NODE IS SMALLER THAN THE CHILD NODE(FOR MIN HEAP)
	// 3. push: upheapify
	// 4. pop: downheapify
	// COMPLETE BINARY TREE: binary tree in which all the levels are completely filled except possibly the lowest one, which is filled from the left.
	priorityQueue obj;
	obj.push(10);
	obj.push(5);
	obj.push(14);
	obj.push(80);
	obj.push(2);
	obj.push(1);
	for (auto ele : obj.data) cout << ele << " ";
	cout << endl;
	obj.pop();
	for (auto ele : obj.data) cout << ele << " ";
	cout << endl;
	obj.pop();
	for (auto ele : obj.data) cout << ele << " ";
	cout << endl;
	obj.pop();
	for (auto ele : obj.data) cout << ele << " ";
	cout << endl;
	obj.pop();
	for (auto ele : obj.data) cout << ele << " ";
	cout << endl;

}
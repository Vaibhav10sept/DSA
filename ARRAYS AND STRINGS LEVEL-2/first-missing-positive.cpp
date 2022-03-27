#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> arr) {
	// step 1: mark element which are out of range and manage the presence of one.
	bool isOnePresent = false;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 1) isOnePresent = true;
		if (arr[i] < 1 or arr[i]>arr.size()) {
			arr[i] = 1;
		}
	}
	if (isOnePresent == false) return 1; // 1 is missing

	// step 2:  map element with index
	for (int i = 0; i < arr.size(); i++) {
		int ind = abs(arr[i]); // think why it can be negative(logic)
		arr[ind - 1] = -1 * abs(arr[ind - 1]);
	}

	//step 3: find out the missing +ve integer
	for (int i = 0; i < arr.size(); i++) {
		// if element is +ve that means i + 1 is missing.
		if (arr[i] > 0) return i + 1;
	}

	return arr.size() + 1;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=QeBvfH1dpOU&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=43
	// QUESTION:
	// Given an unsorted integer array nums, return the smallest missing positive integer.

	// You must implement an algorithm that runs in O(n) time and uses constant extra space.
	//*********************************
	vector<int> arr = { 1, 2, 0};
	cout << "first missing positve number is: " << firstMissingPositive(arr);

}
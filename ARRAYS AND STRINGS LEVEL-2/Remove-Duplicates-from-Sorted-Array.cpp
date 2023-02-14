#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {
	//nice question, think logic, no extra memory is used.
	int count = 0;
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1]) count++;
		else arr[i - count] = arr[i];
	}
	return n - count;
}

int main() {
	/*********************************
	 * NOTE: Nice question
	 * LEETCODE LINK: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
	*********************************/
	vector<int> arr = {1, 1, 2};
	cout << removeDuplicates(arr);
}

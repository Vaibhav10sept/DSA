#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {
	int count = 0;
	int n = arr.size();
	int j = 1;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			arr[j] = arr[i + 1];
			j++;
		}
		else count++;
	}
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
	return j;
}

int main() {
	/*********************************
	 * NOTE: Nice question
	 * LEETCODE LINK: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
	*********************************/
	vector<int> arr = {1, 1, 2};
	cout << removeDuplicates(arr);
}

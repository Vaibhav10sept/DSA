#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {
	// NOTE: the code is written by me, no need to watch video
	int n = arr.size();
	int i = 1;
	int j = 1;
	while (i < n) {
		if (arr[i] == arr[i - 1]) {
			i++;
			continue;
		}

		else {
			arr[j] = arr[i];
			j++;
			i++;
		}
	}

	return j;
}

int main() {
	/*********************************
	 * NOTE: the code is written by me, no need to watch video
	 * NOTE: Nice question
	 * LEETCODE LINK: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
	*********************************/
	vector<int> arr = {1, 1, 2};
	int ans = removeDuplicates(arr);
	cout << "after removing duplicates" << endl;
	for (int i = 0; i < ans; i++) {
		cout << arr[i] << " ";
	}
}

#include <bits/stdc++.h>
using namespace std;

void wiggleSort2(vector<int> &arr) {
	//LOGIC:
	// even indexes are less than odd indexes
	// odd indexes are greater than even indexes
	vector<int> res(arr);
	sort(res.begin(), res.end());
	int j = arr.size() - 1;
	int i = 1;
	while (j >= 0) {
		arr[i] = res[j];
		j--;
		i += 2;
		if (i >= arr.size()) i = 0;
	}
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=mwsjU6CHOb4&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=27
	// QUESTION:
	// 1. Given an integer array 'arr'.
	// 2. Reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
	// 3. You may assume the input array always has a valid answer.
	// Note : You can return answer in any order.
	//*********************************
	vector<int> arr = {1, 5, 1, 1, 6, 4};
	wiggleSort2(arr);
	for (auto ele : arr) cout << ele << " ";
}
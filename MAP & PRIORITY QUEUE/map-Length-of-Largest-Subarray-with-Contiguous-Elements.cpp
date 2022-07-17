#include <bits/stdc++.h>
using namespace std;

int LengthOfLargestSubarrayWithContiguousElements(vector<int> arr) {
	//LOGIC: max - min == len of subarray(no duplicate) tab subarray me continuous ele hote hai
	//think, watch video
	//TIME: O(N^2)
	int ans = 0;

	for (int i = 0; i < arr.size() - 1; i++) {
		int minValue = arr[i];
		int maxValue = arr[i];
		set<int> cd; //ye duplicacy ko rokne ke lie
		cd.insert(arr[i]);

		for (int j = i + 1; j < arr.size(); j++) {
			if (cd.find(arr[j]) != cd.end()) { //present
				//means duplicate ele aa gae toh contiguous nhi ho skta, break.
				break;
			}
			cd.insert(arr[j]);

			minValue = min(minValue, arr[j]);
			maxValue = max(maxValue, arr[j]);
			if (maxValue - minValue == j - i) {
				int len = j - i + 1;
				ans = max(len, ans);
			}
		}
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=37MdIo-MaSU&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=8
	QUESTION LINK: https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/
	*/
	cout << "ans" << endl;
	vector<int> arr = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
	cout << LengthOfLargestSubarrayWithContiguousElements(arr) << endl;
}
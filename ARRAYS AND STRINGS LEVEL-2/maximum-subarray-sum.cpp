#include <bits/stdc++.h>
using namespace std;

// int maxSubarray(vector<int> arr) {
// 	int maxsum = INT_MIN;
// 	int currsum = 0;

// 	for (auto ele : arr) {
// 		currsum += ele;
// 		maxsum = max(currsum , maxsum);
// 		if (currsum < 0) {
// 			currsum  = 0;
// 		}
// 	}
// 	return maxsum;
// }

int maxSubarray(vector<int> arr) {
	int maxsum = arr[0];
	int currsum = arr[0];

	for (int i = 1; i < arr.size(); i++) {
		int ele = arr[i];
		currsum = max(currsum + ele, ele);
		maxsum = max(currsum, maxsum);
	}
	return maxsum;
}

int main() {
	//*********************************
	// NOTE: there is kadane's algo also to solve this question(code commented)
	// NOTE: kadane's algo
	// VIDEO LINK: https://www.youtube.com/watch?v=fxT9KjakYPM
	// LEETCODE LINK:
	//*********************************
	vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxSubarray(arr);
}
#include <bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> arr) {
	int maxsum = INT_MIN;
	int currsum = 0;

	for (auto ele : arr) {
		currsum += ele;
		maxsum = max(currsum , maxsum);
		if (currsum < 0) {
			currsum  = 0;
		}
	}
	return maxsum;
}

int main() {
	//*********************************
	// NOTE: kadane's algo
	// VIDEO LINK: https://www.youtube.com/watch?v=Lmv6wi9WuBQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=62
	// LEETCODE LINK:
	//*********************************
	vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxSubarray(arr);
}
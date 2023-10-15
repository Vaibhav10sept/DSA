#include<bits/stdc++.h>
using namespace std;

bool isValid(int mid, int threshold, vector<int> arr) {
	//mid --> divisor
	int sum = 0;
	for (int ele : arr) {
		sum += ceil((double)ele / mid);
		if (sum > threshold) return false;
	}

	return sum <= threshold;
}

int findSmallestDivisorGivenThreshold(vector<int> arr, int threshold) {
	//watch video recommended
	//edge case:if we cannot form the m number of bouquets, return -1
	// if ((long)m * k > arr.size()) return -1; //long coz leetcode me overflow ho rha tha for a testcase.

	int n = arr.size();
	int end = *max_element(arr.begin(), arr.end());
	int start = 1;
	int ans = 0;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		//mid --> divisor, and we need to minimize this(mid/divisor)
		//and we are trying to minimize day(mid)

		if (isValid(mid, threshold, arr)) {
			ans = mid; //always minimum hi hoga, std::min() ki jrurt nhi, lga bhi doge toh koi farak nhi pdega
			end = mid - 1; //moving left, kyoki hame mid(divisor) ko minimize krna hai
		}
		else { //not valid, means mid(divisor) se arr ke elements ko divide krne pr jo sum aa rha hai vo greater then threshold hai
			//move right
			start = mid + 1;
		}
	}
	return ans;
}

int main() {
	/*
	NOTE: binary search is used here.
	NOTE: i wrote code after wv
	SIMILAR TO: min number of days to make m bouquets
	LEETCODE LINK: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
	VIDEO LINK: https://www.youtube.com/watch?v=UvBKTVaG6U8&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=15
	*/

	vector<int> nums = {1, 2, 5, 9};
	int threshold = 6;
	cout << findSmallestDivisorGivenThreshold(nums, threshold);
}
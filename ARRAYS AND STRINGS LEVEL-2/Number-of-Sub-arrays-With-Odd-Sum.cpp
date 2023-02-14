#include <bits/stdc++.h>
using namespace std;

int noOfSubarrayWithOddSum(vector<int> arr) {
	int ans = 0;
	int evenCount = 0;
	int oddCount = 0;
	int prefixSum = 0;
	//LOGIC:
	// even = even + even
	// even = odd + odd

	// odd = even + odd
	for (int ele : arr) {
		prefixSum += ele;

		if (prefixSum % 2 == 0) { //even prefix sum
			// logic: odd = even + odd
			ans += oddCount;
			evenCount++;
		}
		else { //odd prefix sum
			ans += 1 + evenCount; // +1 coz odd sum hoga agr kisi ko remove nhi kroge, or even vale ko remove kroge toh odd sum hoga
			oddCount++;
		}
		//ye question me dia tha ki mod lena hai.
		ans %= (1000000000 + 7);
	}

	return ans;
}

int main() {
	//*********************************
	// NOTE:
	// LEETCODE LINK: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
	// VIDEO LINK: https://www.youtube.com/watch?v=svvIB5pPc2E&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=79
	//*********************************
	vector<int> arr = {1, 3, 5};
	cout << noOfSubarrayWithOddSum(arr);
}
#include <bits/stdc++.h>
using namespace std;

int waysToMakeAFairArray(vector<int> arr) {
	// nice question(medium) watch video.
	int ans = 0;
	int n = arr.size();
	vector<int> prefixOddSum(n);
	vector<int> prefixEvenSum(n);

	//filling the prefix odd and even sum array
	int oddsum = 0;
	int evensum = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			evensum += arr[i];
		}
		else {
			oddsum += arr[i];
		}
		prefixOddSum[i] = oddsum;
		prefixEvenSum[i] = evensum;
	}

	//calculation ans using the prefixoddsum and prefixevensum
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			//0th index remove hoga toh sare index change hoge(means odd ka even hoga or even ka odd)
			int newOddSum = prefixEvenSum[n - 1] - arr[0];
			int newEvenSum = prefixOddSum[n - 1]; //becoz 0 even hota hai, toh no need to substract

			if (newOddSum == newEvenSum)
				ans++;
		}
		else { // i != 0
			// logic: i se pehle sare index same rhege, i ke baad ke interchange ho jaege
			int newEvenSum = prefixEvenSum[i - 1] + (prefixOddSum[n - 1] - prefixOddSum[i]); // bracket vala part tumhe i+1 se n-1 tak ka sum dege(think)
			int newOddSum = prefixOddSum[i - 1] + (prefixEvenSum[n - 1] - prefixEvenSum[i]);

			if (newOddSum == newEvenSum)
				ans++;
		}
	}
	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=s0JtNntehsM&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=55
	// QUESTION:
// You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.

// For example, if nums = [6,1,7,4,1]:

// Choosing to remove index 1 results in nums = [6,7,4,1].
// Choosing to remove index 2 results in nums = [6,1,4,1].
// Choosing to remove index 4 results in nums = [6,1,7,4].
// An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.

// Return the number of indices that you could choose such that after the removal, nums is fair.
	//*********************************
	vector<int> arr = {2, 1, 6, 4};
	// vector<int> arr = {1, 1, 1};
	cout << waysToMakeAFairArray(arr);
}
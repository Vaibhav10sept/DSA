#include <bits/stdc++.h>
using namespace std;

int rec(int index, int diff, vector<int> &arr, vector< unordered_map<int, int>> &memo) {
	if (index < 0) return 0;
	//BC ends

	if (memo[index].find(diff) != memo[index].end()) return memo[index][diff];

	int ans = 0;
	for (int j = index - 1; j >= 0; j--) {
		if (arr[index] - arr[j] == diff) {
			ans = max(ans, 1 + rec(j, diff, arr, memo));
		}
	}

	return memo[index][diff] = ans;
}

int longestArithmaticSubsequence(vector<int> arr) {
	int n = arr.size();
	if (n <= 2) return n; //edge case(think, cs)

	vector< unordered_map<int, int>> memo(n + 1);
	//storage: means memo ke har index me ek map hoga jo diff->length ko store krega

	int maxLength = INT_MIN;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			int currDiff = arr[j] - arr[i]; //note: arr is increasing
			maxLength = max(maxLength, 2 + rec(i, currDiff, arr, memo));
		}
	}
	return maxLength;
}


int main()
{
	/***************************
	 * NOTE: this will give TLE, a DP solution is also there.
	 * NOTE: this is memoized rec solution
	 * NOTE: wv recommended
	VIDEO LINK: https://www.youtube.com/watch?v=YaMcX7sem70&t=2s
	LEETCODE LINK: https://leetcode.com/problems/longest-arithmetic-subsequence/
	//**************************************************/
	vector<int> arr = {12, 28, 13, 6, 34, 36, 53, 24, 29, 2, 23, 0, 22, 25, 53, 34, 23, 50, 35, 43, 53, 11, 48, 56, 44, 53, 31, 6, 31, 57, 46, 6, 17, 42, 48, 28, 5, 24, 0, 14, 43, 12, 21, 6, 30, 37, 16, 56, 19, 45, 51, 10, 22, 38, 39, 23, 8, 29, 60, 18};
	cout << longestArithmaticSubsequence(arr);
}
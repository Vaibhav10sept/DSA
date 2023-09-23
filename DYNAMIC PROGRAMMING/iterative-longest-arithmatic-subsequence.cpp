#include <bits/stdc++.h>
using namespace std;

int solve(int index, int diff, vector<int> arr) {
	int i = index - 1;
	int count = 0;
	int lastValue = arr[index];

	while (i >= 0) {
		if (lastValue  - arr[i] == diff) {
			lastValue = arr[i];
			count++;
		}
		i--;
	}

	return count;
}

int longestArithmaticSubsequence(vector<int> arr) {
	int maxLength = INT_MIN;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			int currDiff = arr[j] - arr[i]; //note: arr is increasing
			maxLength = max(maxLength, 2 + solve(i, currDiff, arr));
		}
	}
	return maxLength;
}


int main()
{
	/***************************
	 * NOTE: this will give TLE other solution are also there.
	 * NOTE: wv recommended
	VIDEO LINK: https://www.youtube.com/watch?v=YaMcX7sem70&t=2s
	LEETCODE LINK: https://leetcode.com/problems/longest-arithmetic-subsequence/
	//**************************************************/
	vector<int> arr = {3, 6, 9, 12};
	cout << longestArithmaticSubsequence(arr);
}
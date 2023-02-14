#include <bits/stdc++.h>
using namespace std;

int arithmaticSlice2(vector<int> arr) {
	// WV highly recommended.
	int ans = 0;
	vector<map<int, int>> dp(arr.size());
	//storage: dp[i] --> map(int vs int) --> common diff  vs  count of subsequences with that common difference ending at 'i'th element with lenght >= 2.

	for (int i = 1; i < arr.size(); i++) {
		for (int j = 0; j < i; j++) {
			long commonDiff = arr[i] - arr[j]; //long because diff jo hai vo integer ki range se bahar ja skta h.

			int countOfAPEndingAtI = dp[i][commonDiff]; // AP --> arithmatic progression
			int countOfAPEndingAtJ = dp[j][commonDiff]; // AP --> arithmatic progression

			ans += countOfAPEndingAtJ; //think, WV
			dp[i][commonDiff] += (countOfAPEndingAtJ + 1);
		}
	}
	return ans;
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=XjLT4TaXsgw
	// LEETCODE: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/
	// NOTE: there is a first part of this question "arithmatic slice" which deals with subsequence
	//**************************************************
	vector<int> arr = {2, 4, 6, 8, 10};
	cout << arithmaticSlice2(arr);

}
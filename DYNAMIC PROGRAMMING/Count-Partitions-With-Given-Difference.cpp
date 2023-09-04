#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int countSubsetsWithSumKStriverSolution(vector<int> arr, int target) {
	//this can handle if the array has zero.
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(target + 1, 0));

	//initialization
	if (arr[0] == 0) dp[0][0] = 2; //if sum=0 and at index=0, 0 is present then there are two cases with which we can get 0 sum ie. including 0 or excluding 0, WV recommended
	else dp[0][0] = 1; //else if 0th index is not 0 then only one case ie. we need to exclude it to become 0 sum other we get negative sum, WV recommended


	// for (int i = 1; i < arr.size(); i++) {
	// 	dp[i][0] = 1;
	// }
	//why above code is commented, dry run recommended maene krke dekha tha sb smjh aya tha


	if (arr[0] != 0 and arr[0] <= target) dp[0][arr[0]] = 1; //pay attention to this "arr[0] != 0" agr arr[0] 0 hoga to dp[0][0] 1 hojaegi lekin upr to hmne dp[0][0] ko 2 kia h if arr[0] == 0, so ye contradiciting hoga islie arr[0] != 0 vali condition jruri hai(WV recommended)
	//initialization ends

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= target; j++) {
			int notTake = dp[i - 1][j];
			int take = 0;
			if (arr[i] <= j) {
				take = dp[i - 1][j - arr[i]];
			}

			dp[i][j] = (take + notTake) % mod;
		}
	}
	return dp[n - 1][target];

}

int countPartitionsWithGivenDifference(vector<int> arr, int diff) {
	int totalSum = 0;
	for (auto ele : arr) totalSum += ele;

	if ((totalSum - diff) % 2 == 1 or totalSum - diff < 0) {
		//totalSum - diff should be even and positive (coz of the fomula for target = (totalSum - diff) / 2)
		return 0;
	}

	int target = (totalSum - diff) / 2;
	cout << "target " << target << endl;
	return countSubsetsWithSumKStriverSolution(arr, target);
}

int main()
{
	/***************************
	 * SIMILAR/SAME CODE AS THIS ONE: target sum(https://leetcode.com/problems/target-sum/description/)
	NOTE: we just need to calculate the target(using formula, WV)
	PREREQUISITE: count subsets with sum k(just target has to be calculated every thing else will remain the same)
	VIDEO LINK: https://www.youtube.com/watch?v=zoilQD1kYSg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=19
	QUESTION LINK: https://www.geeksforgeeks.org/count-of-subsets-with-given-difference/#:~:text=Given%20an%20array%20arr%5B%5D,equal%20to%20the%20given%20difference.
	subset/subsequence: 2^n; har element ke pass 2 option hai ya toh subset me aae
	ya na aae
	subarray: N*(N+1)/2; subarray continuous hote hai
	//**************************************************/
	vector<int> arr =  {1, 0, 8, 5, 1, 4};
	int diff = 17;

	cout << "result " << countPartitionsWithGivenDifference(arr, diff);
}
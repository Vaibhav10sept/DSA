#include <bits/stdc++.h>
using namespace std;

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

			dp[i][j] = (take + notTake);
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

int targetSum(vector<int> arr, int target) {
	return countPartitionsWithGivenDifference(arr, target);
}


int main()
{
	/***************************
	STRONG PRE: count partitions with given difference
	// NOTE: this is the exact same question as in count partitions with given difference.
	// SAME CODE AS IN: count partitions with given difference.(WV recommended)
	// NOTE: this recusive solution will give you TLE, other solution are also there, search
	// NOTE: there is a memoized and dp solution also.
	//       you can search it using ctrl + p.
	// VIDEO LINK: https://leetcode.com/problems/target-sum/
	// LEETCODE LINK: https://www.youtube.com/watch?v=b3GD8263-PQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=22
	//**************************************************/
	vector<int> arr = {1, 2, 1};
	int target = 0;

	cout << targetSum(arr, target);
}
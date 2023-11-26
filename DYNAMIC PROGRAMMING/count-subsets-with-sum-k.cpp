#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int perfectSum(int arr[], int n, int target)
{
	vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

	int cnt = 1;
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
	{
		// Explanation:- They have also included zeroes hence the first column ie t[i][0] which signifies
		// no. of elements whose sum is 0 increases with every entry of 0 in the input array by a factor of 2.
		// Eg-> for no zero element we have {} empty subset whose sum is 0. So, for 1 zero element 0 sum
		// count is 2. For 2 zeroes element in the array we have 0 sum count as 4 [{}, {first zero},
		// {second zero}, {both zeroes}]. So, we are counting zeroes and initialising first column
		// accordingly.
		if (arr[i] == 0)
		{
			cnt *= 2;
			dp[i + 1][0] = cnt;
		}
		else
		{	//element is non zero, so only one count ie. empty set
			dp[i + 1][0] = 1;
		}

	}

	int mod = (int)1e9 + 7;
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < target + 1; ++j)
		{
			if (arr[i - 1] <= j)
			{
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	displayMatrix(dp);

	return dp[n][target];

}

int main()
{
	/***************************
	 * STRONG PREQ: subset sum dp
	NOTE: this sol also contains the code to handle 0 element in array(copied from a comment of the attached video, but pura smjh me aa gya)
	 * NOTE: there is a recursive solution also.
	VIDEO LINK: https://www.youtube.com/watch?v=F7wqWbqYn9g
	QUESTION LINK: https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
	subset/subsequence: 2^n; har element ke pass 2 option hai ya toh subset me aae
	ya na aae
	subarray: N*(N+1)/2; subarray continuous hote hai
	//**************************************************/
	vector<int> arr = {9, 6, 1, 2, 6, 8, 5};
	int arr1[] =  {9, 6, 1, 2, 6, 8, 5};
	int target = 7;
	int n = 7;
	cout << perfectSum(arr1, n, target) << endl;
	cout << "result " << countSubsetsWithSumKStriverSolution(arr, target);
}
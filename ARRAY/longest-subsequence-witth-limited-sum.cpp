#include <bits/stdc++.h>
using namespace std;

vector<int> longestSubsequenceWithLimitedSum(vector<int> arr, vector<int> queries) {
	vector<int> res(queries.size(), 0);
	//please read the below approach for better understanding
	sort(arr.begin(), arr.end());

	for (int i = 0; i < queries.size(); i++) {
		int sum = 0;
		int ind = 0;
		int countOfElements = 0;
		while (ind < arr.size())
		{
			if (sum + arr[ind] <= queries[i]) {
				sum += arr[ind];
				countOfElements++;
			}
			ind++;

		}
		res[i] = countOfElements;
	}

	return res;
}

int main()
{
	/***************************************
	 * LEETCODE LINK: https://leetcode.com/problems/longest-subsequence-with-limited-sum/solutions/2948451/100-faster-easy-java-soln-with-explanation/?orderBy=most_votes%5Bleetcode%5D
	 * NOTE: no video leetcode ka link me solution with written explaination hai
	 * Approach
	We first sort the nums array(since we just need to calculate the maximum subsequence length that can add up to queries or less than that).
	We traverse over each element of the queries array and take the elements from the sorted nums array that sum upto queries or less than that.
	Every time we take an element from the nums array we increase our counter variable by 1.
	we add the final counter value to a result array.

	Complexity
	Time complexity: O(mxn)
	m = queries.length.
	n = nums.length.

	Space complexity: O(1)
	 * **************************************/
	vector<int> nums = {4, 5, 2, 1};
	vector<int> queries = {3, 10, 21};
	vector<int> ans = longestSubsequenceWithLimitedSum(nums, queries);
	for (int ele : ans) cout << ele << " ";

}
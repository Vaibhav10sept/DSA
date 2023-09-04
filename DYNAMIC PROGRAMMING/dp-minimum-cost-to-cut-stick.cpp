#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int minCostToCutStick(vector<int> cuts, int n) {
	//we are using gap strategy here, for gap strategy watch the prerequisite videos
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	sort(cuts.begin(), cuts.end());
	// displayMatrix(dp);
	for (int gap = 0; gap < dp.size(); gap++) {
		for (int left = 0, right = gap; left < dp.size() and right < dp[0].size(); left++, right++) {
			if (gap == 0) { //0 size stick, min cost is 0(CS)
				dp[left][right] = 0; //initialization
			}
			else if (gap == 1) { // 1 size ka stick, min cost is 0(one size ki stick ko kese katoge)
				dp[left][right] = 0; //iniitlization
			}
			else {
				int minCost = INT_MAX;
				for (int cut : cuts) {
					if (cut > left and cut < right) { //cut should be in range of left and right
						//copy the recursive code
						int currentCost = right - left;
						int leftSideCost = dp[left][cut];
						int rightSideCost = dp[cut][right];
						minCost = min(minCost, currentCost + leftSideCost + rightSideCost);
					}
					if (cut > right) break;
				}
				if (minCost == INT_MAX) {
					dp[left][right] = 0; //edge case, agr koi bhi cut valid ni hua, "if (cut > left and cut < right)" ye if true ni hua to minCost INTMAX hi rhegi in that case return 0;
				}

				else dp[left][right] = minCost;
			}
		}
	}
	return dp[0][dp[0].size() - 1];
}

int main()
{
	/***************************
	 * NOTE: give TLE on leetcode
	 * NOTE: this code is dervied from the rec-minimum-cost-to-cut-stick
	 * NOTE: please go through the recursive code first and then derive the dp solution
	 * NOTE: gap strategy is used here.
	PREREQUISITE: minimum pallindrome partition or pallindrome partition 2 optimized solution.
	VIDEO: https://www.youtube.com/watch?v=EVxTO5I0d7w
	QUESTION: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
	//**************************************************/
	int n = 7;
	vector<int> cuts = {1, 3, 4, 5};
	cout << minCostToCutStick(cuts, n);
}
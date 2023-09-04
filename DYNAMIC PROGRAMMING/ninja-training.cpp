#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(vector<vector<int>> arr) {
	int n = arr.size();
	vector<vector<int>> dp(arr.size(), vector<int>(4, -1)); //4 size coz neeche hm 3 idx pass kre so to make memoized[day][lastTask] valid we need to make memoized column of size 4 to make 3rd index possible

	//initialization:
	dp[0][0] = max(arr[0][1], arr[0][2]);
	dp[0][1] = max(arr[0][0], arr[0][2]);
	dp[0][2] = max(arr[0][0], arr[0][1]);
	dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

	int lastTask = 4;
	for (int day = 1; day < n; day++) {
		for (int lastTask = 0; lastTask < 4; lastTask++) {
			for (int task = 0; task < 3; task++) {
				if (task != lastTask) {
					int points = arr[day][task] + dp[day - 1][task];
					dp[day][lastTask] = max(dp[day][lastTask], points);
				}
			}
		}
	}
	return dp[n - 1][3];
}


int main()
{
	/***********************************************
	PREQ: max sum non adjacent elements
	NOTE: this is DP, recursive solution is also present.
	QUESTION: https://www.codingninjas.com/studio/problems/ninja-s-training_3621003
	video link: https://www.youtube.com/watch?v=AE39gJYuRog&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=10
	SIMILAR: there is also a similar quest for recursion
	****************************************************/
	vector<vector<int>> arr = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};

	cout << "max merit points is: " << ninjaTraining(arr);
}
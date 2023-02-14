#include <bits/stdc++.h>
using namespace std;

int countClimbStairPathsWithMinMoves(int n, vector<int> jumpArray) {
	vector<int> dp(n + 1, -1);
	dp[n] = 0; //rem: destination tk jane ka path 1 hota hai, par step/move 0 hote hai(think)

	for (int i = n - 1; i >= 0; i--) {
		if (jumpArray[i] > 0) {
			int ans = INT_MAX;

			for (int j = 1; j <= jumpArray[i]; j++) {
				if (i + j < dp.size()) { //check for valid index
					if (dp[i + j] != -1) {
						ans = std::min(ans, dp[i + j]);
					}
				}
			}
			if (ans == INT_MAX) {
				dp[i] = -1;
			}
			else {
				dp[i] = ans + 1;// 1 move iska hoga
			}
		}
	}
	return dp[0];
}

int main()
{
	//**********************************
	//IDENTIFY THE DIFFERENCE BETWEEN PATHS AND MOVES/STEPS
	//AGAR DESTINATION PE HO TOH: NO. OF MOVES = 0; NO. OF PATHS = 1;
	//WATCH VIDEO: https://www.youtube.com/watch?v=Zobz9BXpwYE&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=429
	//**************************************
	int n = 10;
	vector<int> jumpArray = {3, 3, 0, 2, 1, 2, 4, 2, 0, 0};
	cout << "minimum moves: " << countClimbStairPathsWithMinMoves(n, jumpArray);
}
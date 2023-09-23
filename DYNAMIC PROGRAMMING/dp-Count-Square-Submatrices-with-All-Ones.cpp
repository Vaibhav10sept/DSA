#include <bits/stdc++.h>
using namespace std;

int countSquareSubmatricesWithAllOnes(vector<vector<int>> arr) {
	//wv recommended
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));
	int countOfAllSqures = 0;
	//storage: dp[i][j] --> stores the number of squares who ends at i,j(bottom right corner is i,j)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 or j == 0) { //initialization
				dp[i][j] = arr[i][j];
			}
			else if (arr[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1; //+1 coz every index apne me ek size ka square banega hi which ends at i,j(means bottom right index/corner is i,j)
			}
			else { //arr[i][j] == 0
				dp[i][j] = 0; //ab arr[i][j] 0 h to koi bhi square bn hi nhi skta islie dp[i][j] = 0 hoga.
			}
			//in answer we need to return the total count of square, so dp me hmne har index pe end(bottom right corner) ke count store kr rhe h, to answer is the sum of all the counts of square that we have stored in dp
			countOfAllSqures += dp[i][j];
		}
	}

	return countOfAllSqures;
}



int main()
{
	/***************************
	 * STRONG PREQ: maximal squares
	VIDEO LINK: https://www.youtube.com/watch?v=auS1fynpnjo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=57
	LEETCODE LINK: https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
	*****************************/
	vector<vector<int>> matrix =
	{
		{0, 1, 1, 1},
		{1, 1, 1, 1},
		{0, 1, 1, 1}
	};
	cout << countSquareSubmatricesWithAllOnes(matrix);
}
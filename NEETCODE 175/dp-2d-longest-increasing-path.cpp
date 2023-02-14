#include <bits/stdc++.h>
using namespace std;

int longestIncreasingPath(vector<vector<int>> arr) {
	// WV recommended.

}

int main()
{
	/***************************
	 * DP solution is also there
	VIDEO LINK: https://www.youtube.com/watch?v=wCc_nd-GiEc
	QUESTION LINK: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
	//**************************************************/
	vector<vector<int>> arr = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};

	cout << longestIncreasingPath(arr);
}
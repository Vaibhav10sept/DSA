#include <bits/stdc++.h>
using namespace std;

int RecHelper(int i, int j, vector<vector<int>> arr) {
	if (i == arr.size() - 1 and j == arr[0].size() - 1) {
		return 1;
	}
	if (i >= arr.size() or j >= arr[0].size()) return 0;
	if (arr[i][j] == 1) return 0;
	//BC ends


	//recursive calls
	return RecHelper(i + 1, j, arr) + RecHelper(i, j + 1, arr);
}

int uniquePaths2(vector<vector<int>> arr) {
	return RecHelper(0, 0, arr);
}

int main()
{
	/*****************************
	 * NOTE: this rec solution will give you TLE, a DP solution is also there.
	 * LEETCODE LINK: https://leetcode.com/problems/unique-paths-ii/
	 * **************************************/
	vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
	cout << uniquePaths2(obstacleGrid);

}
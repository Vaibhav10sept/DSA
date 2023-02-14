#include <bits/stdc++.h>
using namespace std;

int uniquePathsRecursive(int i, int j, int n, int m) {
	if (i == n - 1 and j == m - 1) { //we have reached the destination, so return 1
		return 1;
	}
	if (i >= n or j >= m) {
		return 0;
	}
	//BC ends

	//recursive calls
	return uniquePathsRecursive(i, j + 1, n, m) + uniquePathsRecursive(i + 1, j, n, m);
}

int uniquePaths(int n, int m) {
	return uniquePathsRecursive(0, 0, n, m);
}

int main() {
	/*********************************
	 * NOTE: this will give you TLE, a DP solution is also there
	LEETCODE: https://leetcode.com/problems/unique-paths/
	VIDEO LINK: https://www.youtube.com/watch?v=t_f0nwwdg5o
	*********************************/
	// string str = "leetcode";
	// vector<string> wordDict = {"leet", "code"};

	int m = 3;
	int n = 7;

	//here, m--> rows and n--> cols
	//so maene func call krte time change kr dia
	//so, now, n--> rows and m--> cols
	cout << uniquePaths(m, n);
}
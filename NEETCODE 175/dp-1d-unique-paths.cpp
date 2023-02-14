#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int n, int m) {
	//WV highly recommended
	//NOTE: this is not 2d DP solution
	int N = n + m - 2;
	int r = n - 1;
	double res = 1;

	for (int i = 1; i <= r; i++) {
		//here, we are finding Ncr (combination maths)
		res = res * (N - r + i) / i;
	}
	return (int)res;
}

int main() {
	/*********************************
	 * NOTE: a recursive code is also there.
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